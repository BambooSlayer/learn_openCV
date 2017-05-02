#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) 
{

////////////显示图像
	Mat image;
    image = imread("4.jpg");
    //Mat image(200,200, CV_8UC3, Scalar(0,200,0));
	 Mat hsvimage,hue;
	imshow("image", image);
	// cout << "M = " << endl << " " << image << endl << endl;
	  cvtColor(image, hsvimage, CV_BGR2HSV); 
	 // imshow("HSV", hsvimage); 
   vector<Mat> hsv;	   
   split(hsvimage,hsv);
   //merge(hsv,hue);
   int Len1=hsvimage.rows;
   int Len2=hsvimage.cols;
   int avgH=50,dis=20;
   for(int i=0;i<Len2;i++)
   {
	   for(int j=0;j<Len1;j++)
	   {
		   if((hsv[0].at<uchar>(j,i))<=(avgH+dis) && hsv[0].at<uchar>(j,i)>=(avgH-dis))
				//&&(hsv[1].at<uchar>(j,i))<=(avgS+40) && hsv[1].at<uchar>(j,i)>=(avgS-40))
			{
				hsv[0].at<uchar>(j,i)=0;//找到绿色，替换成红色。（以后改成其他mark，这里为了方便显示
			}
	   }
   }
		merge(hsv,hue);
	   cvtColor(hue,image,  CV_HSV2BGR); 
	  imshow("RGB2", image); 


        //用彩色图像形象的表示一下,除了原通道保留，其余两通道置0
       /* 
	   Mat tmp(image.size(),CV_8U,Scalar(0));
        
		vector<Mat> h,s,v;   //用来表示的彩色图像
        for(int i=0;i<3;i++)
        {
                if(i==0)
                        h.push_back(hsv[0]);
                else
                        h.push_back(tmp);

                if(i==1)
                        s.push_back(hsv[1]);
                else
                        s.push_back(tmp);

                if(i==2)
                        v.push_back(hsv[2]);
                else
                        v.push_back(tmp);
        }
		merge(h,hue);
	   imshow("H", hue);
	   merge(s,hue);
	   imshow("S", hue); 
	   merge(v,hue);
	   imshow("V", hue); 
	   */



	  while(1)
  {
      char c=cvWaitKey(33);
      if(c==27)break;		//等待按键ESC
  }
////////捕获摄像头
 //获取摄像头
VideoCapture capture(1);//0或-1表示笔记本内置摄像头

Mat frame;
capture  >> frame;
Len1=frame.rows;
Len2=frame.cols;
//avgH=50,dis=10;
  while(1)
  {
	cvtColor(frame, hsvimage, CV_BGR2HSV); 
	split(hsvimage,hsv);
   for(int i=0;i<Len2;i++)
   {
	   for(int j=0;j<Len1;j++)
	   {
		   if((hsv[0].at<uchar>(j,i))<=(avgH+dis) && hsv[0].at<uchar>(j,i)>=(avgH-dis))
				//&&(hsv[1].at<uchar>(j,i))<=(avgS+40) && hsv[1].at<uchar>(j,i)>=(avgS-40))
			{
				hsv[0].at<uchar>(j,i)=0;//找到绿色，替换成红色。（以后改成其他mark，这里为了方便显示
			}
	   }
   }
		merge(hsv,hue);
	   cvtColor(hue,frame,  CV_HSV2BGR); 
		imshow("读取视频", frame);
		capture  >> frame;
		
      char c=cvWaitKey(33);
      if(c==27)break;		//等待按键ESC
  }

return 0;
}