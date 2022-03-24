#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


class iTransform {
	public:
		Mat iNormal(Mat &img);
		vector<Mat> iResize(Mat &img);
		Mat iHFlip(Mat &img);
		Mat iRotate(Mat &img, double ang, bool keep=false);
};