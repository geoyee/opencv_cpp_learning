#include <iostream>
#include <opencv2/opencv.hpp>
// #include "iConvert.h"
// #include "iMat.h"
// #include "iTrack.h"
// #include "iDraw.h"
// #include "iROI.h"
#include "iTransform.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("-- IN --\n");
	iTransform trans;
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	Mat img_normal = trans.iNormal(img);
	imshow("NORMAL", img_normal);
	// vector<Mat> r_imgs = trans.iResize(img);
	// imshow("ZOOMIN", r_imgs[0]);
	// imshow("ZOOMOUT", r_imgs[1]);
	Mat ro_img = trans.iRotate(img, 37, true);
	imshow("ROTATE", ro_img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}