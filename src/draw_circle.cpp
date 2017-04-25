/*************************************************************************
    > File Name: draw_circle.cpp
    > Author: laoding
    > Mail: dyg1993@foxmail.com 
    > Created Time: 一  4/24 21:02:09 2017
 ************************************************************************/

#include<iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "common.h"
using namespace std;
using namespace cv;



void draw_circle()
{
	//Mat img = Mat::zeros(Size(500,500),CV_8UC1);
	Mat img(500,500,CV_8UC3,Scalar(0,0,0));
	circle(img,Point(250,250),40,Scalar(255));

	circle(img,Point(250,250),20,Scalar(255),-1);
	imshow("circle",img);
	waitKey(0);
}

void gen_circle_mask(Mat & mask,Point center,int radius)
{
	circle(mask,center,radius,Scalar(255,255,255),-1);
}

void usage()
{
	cout << "draw_circle -i  ../../data/test.jpg" << endl;
	exit(0);
}
int main(int argc,char ** argv)
{
	CmdLineParser cml(argc,argv);
	if(argc < 3 || cml["-h"])
	{
		usage();
	}
//	draw_circle();
	string src_name = cml("-i","../../data/test.jpg");
	Mat src = imread(src_name,1);
	Mat mask(src.size(),src.type(),Scalar(0,0,0));

	Point center = src.size() / 2;
	int radius = 40;

	gen_circle_mask(mask,center,radius);

	src &= mask;
	imshow("src",src);

	imshow("mask",mask);
	waitKey(0);
	return 0;
}

