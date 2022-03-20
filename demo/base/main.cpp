#include <iostream>
#include <opencv2/opencv.hpp>
#include "iconvert.h"
#include "iMat.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("-- IN --\n");
	iConverter cvt;
	iMat m;
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	Mat img_add = m.add(img, 20);
	Mat gray = cvt.toGray(img_add);
	Mat igray = m.ergodicInv2(gray);
	m.showInfo(igray);
	m.trackAdd(gray);
	imshow("IGRAY", igray);
	waitKey(0);
	destroyAllWindows();
	return 0;
}