#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
	printf("hello world!");
	Mat img = imread("E:/dataFiles/github/opencv_cpp_learning/assets/RS/00GOQ3IKOT.jpg");
	imshow("build", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}