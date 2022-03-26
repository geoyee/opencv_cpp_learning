#include <iostream>
#include <opencv2/opencv.hpp>
#include "iDeepFace.h"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	iDeepFace idf;
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/images/People/t.jpg");
	Mat dimg = idf.det(img);
	imshow("FaceDetection", dimg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}