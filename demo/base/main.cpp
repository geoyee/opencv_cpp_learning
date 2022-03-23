#include <iostream>
#include <opencv2/opencv.hpp>
#include "iConvert.h"
#include "iMat.h"
#include "iTrack.h"
#include "iDraw.h"
#include "iROI.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("-- IN --\n");
	// iConverter cvt;
	iMat m;
	// iTrack track;
	// iDraw dr;
	iROI roi;
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	m.showInfo(img);
	// img = cvt.splitAndMerge(img);
	// Mat mask = cvt.inRangGreen(img);
	// track.trackAdd(img);
	// cvt.keyConverter(img);
	// Mat dr_im = dr.baseDrawDemo(img);
	// imshow("test", dr_im);
	// waitKey(0);
	// destroyAllWindows();
	// dr.randLineDemo(Size(512, 512));
	roi.roiSelected(img);
	return 0;
}