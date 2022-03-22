#include <iostream>
#include <opencv2/opencv.hpp>
#include "iConvert.h"
#include "iMat.h"
#include "iTrack.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("-- IN --\n");
	iConverter cvt;
	iMat m;
	// iTrack track;
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	m.showInfo(img);
	// img = cvt.splitAndMerge(img);
	Mat mask = cvt.inRangGreen(img);
	// track.trackAdd(img);
	// cvt.keyConverter(img);
	imshow("mask", mask);
	waitKey(0);
	destroyAllWindows();
	return 0;
}