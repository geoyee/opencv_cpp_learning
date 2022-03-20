#include <opencv2/opencv.hpp>

using namespace cv;


class iMat {
	public:
		Mat copy(Mat &img);
		Mat constValue(Size size, int value);
		void showInfo(Mat &img);
		Mat ergodicInv(Mat &img);
		Mat ergodicInv2(Mat &img);
		Mat add(Mat &img, int value);
		void trackAdd(Mat &img, int value=100);
};