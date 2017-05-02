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
	  imshow("HSV", hsvimage); 
  vector<Mat> hsv;	   
   split(hsvimage,hsv);
   //merge(bgr,hue);
        //用彩色图像形象的表示一下,除了原通道保留，其余两通道置0
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
	  while(1)
  {
      char c=cvWaitKey(33);
      if(c==27)break;		//等待按键ESC
  }
////////捕获摄像头
 //获取摄像头
VideoCapture capture(1);//0或-1表示笔记本内置摄像头

Mat frame;
  while(1)
  {
		capture  >> frame;
		imshow("读取视频", frame);
      char c=cvWaitKey(33);
      if(c==27)break;		//等待按键ESC
  }

return 0;
}