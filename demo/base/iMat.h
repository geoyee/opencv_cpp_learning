#include <opencv2/opencv.hpp>

using namespace cv;


class iMat {
	public:
		Mat iCopy(Mat &img);
		Mat constValue(Size size, int value);
		void showInfo(Mat &img);
		Mat ergodicInv(Mat &img);
		Mat ergodicInv2(Mat &img);
		Mat iAdd(Mat &img, int value);
		Mat iMul(Mat &img, double value);
		void trackAdd(Mat &img, int max_alpha=100, int max_beta=100);
};