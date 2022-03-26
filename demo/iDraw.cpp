#include <iostream>
#include <opencv2/opencv.hpp>
#include "iDraw.h"

using namespace std;
using namespace cv;


Mat iDraw::baseDrawDemo(Mat &img) {
	Mat im = img.clone();
	rectangle(im, Rect(10, 10, 20, 20), Scalar(0, 0, 255), 2, 8, 0);
	circle(im, Point(50, 50), 30, Scalar(255, 0, 0), -1, 8, 0);
	line(im, Point(20, 20), Point(50, 50), Scalar(0, 255, 255));
	ellipse(im, RotatedRect(Point2f(100, 100), Size2f(50, 200), 45.0), Scalar(255, 255, 0), 1, LINE_AA);
	return im;
}


void iDraw::randLineDemo(Size size) {
	Mat canvas = Mat::zeros(size, CV_8UC3);
	RNG rng(2022);
	Point start = Point(int(size.width / 2), int(size.height / 2));
	while (true)
	{
		int c = waitKey(1);
		if (c == 27) {
			break;
		}
		Point end = Point(rng.uniform(0, size.width), rng.uniform(0, size.height));
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		// cout << start << "\n" << end << "\n" << color << endl;
		line(canvas, start, end, color);
		imshow("RANDLINES", canvas);
	}
	destroyAllWindows();
}


void iDraw::polygonDemo() {
	Mat canvas1 = Mat::zeros(Size(512, 512), CV_8UC3);
	Mat canvas2 = canvas1.clone();
	vector<Point> pts;
	pts.push_back(Point(100, 150));
	pts.push_back(Point(215, 333));
	pts.push_back(Point(420, 288));
	pts.push_back(Point(20, 410));
	Scalar color = Scalar(255, 255, 0);
	// 方法一
	fillPoly(canvas1, pts, color);
	polylines(canvas1, pts, true, color);
	// 方法二
	vector<vector<Point>> ptss;
	ptss.push_back(pts);
	drawContours(canvas2, ptss, -1, color, -1);
	imshow("Poly_1", canvas1);
	imshow("Poly_2", canvas2);
	waitKey(0);
	destroyAllWindows();
}