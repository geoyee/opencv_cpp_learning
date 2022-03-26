#include <iostream>
#include <opencv2/opencv.hpp>
#include "iROI.h"

using namespace std;
using namespace cv;


Point start = Point(-1, -1);

static void mouseCall(int ev, int x, int y, int flags, void* usrdata) {
	Mat img = *(Mat*)usrdata;
	Mat im = img.clone();
	if (ev == EVENT_LBUTTONDOWN) {
		start = Point(x, y);
	}
	else if (ev == EVENT_MOUSEMOVE) {
		// cout << start << endl;
		if (start.x > 0 && start.y > 0) {
			img.copyTo(im);
			rectangle(im, Rect(start, Point(x, y)), Scalar(0, 0, 127));
			imshow("ROI_SELECTED", im);
		}
	}
	else if (ev == EVENT_LBUTTONUP) {
		if (start.x != x && start.y != y)
		{
			img.copyTo(im);
			Rect rect = Rect(start, Point(x, y));
			rectangle(im, rect, Scalar(0, 0, 255));
			imshow("ROI_SELECTED", im);
			imshow("ROI", im(rect));  // 如何改变最小宽度
			start = Point(-1, -1);
		}
	}
}

void iROI::roiSelected(Mat &img) {
	namedWindow("ROI_SELECTED", WINDOW_AUTOSIZE);
	imshow("ROI_SELECTED", img);
	setMouseCallback("ROI_SELECTED", mouseCall, &img);
	waitKey(0);
	destroyAllWindows();
}