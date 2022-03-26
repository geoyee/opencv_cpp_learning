#include <opencv2/opencv.hpp>

using namespace cv;


class iHist {
	public:
		void showHist(Mat &img);
		void showHist2D(Mat &img);
		Mat histEQ(Mat &img);
};