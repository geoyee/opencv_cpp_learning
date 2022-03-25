#include <iostream>
#include <opencv2/opencv.hpp>
// #include "iConvert.h"
// #include "iMat.h"
// #include "iTrack.h"
// #include "iDraw.h"
// #include "iROI.h"
// #include "iTransform.h"
#include "iHist.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("-- IN --\n");
	iHist ih;
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	Mat img_eq_hist = ih.histEQ(img);
	imshow("IMG", img);
	imshow("EQHIST", img_eq_hist);
	waitKey(0);
	destroyAllWindows();
	return 0;
}