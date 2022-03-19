#include <iostream>
#include <opencv2/opencv.hpp>
#include "iconvert.h"
#include "iMat.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("-- IN --\n");
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	iConverter cvt;
	Mat gray = cvt.toGray(img);
	iMat m;
	Mat igray = m.ergodicInv2(gray);
	m.showInfo(igray);
	imshow("GRAY", gray);
	imshow("IGRAY", igray);
	waitKey(0);
	destroyAllWindows();
	return 0;
}