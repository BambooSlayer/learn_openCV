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
    image = imread("1.jpg");
       imshow("image", image);
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