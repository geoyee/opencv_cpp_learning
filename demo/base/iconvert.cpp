#include "iconvert.h"


Mat iConverter::toGray(Mat &img) {
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	return gray;
}


Mat iConverter::toHSV(Mat &img) {
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	return hsv;
}