#include <iostream>
#include <opencv2/opencv.hpp>
#include "iConvert.h"
#include "iMat.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("-- IN --\n");
	iConverter cvt;
	iMat m;
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	m.showInfo(img);
	// m.trackAdd(img);
	cvt.keyConverter(img);
	return 0;
}