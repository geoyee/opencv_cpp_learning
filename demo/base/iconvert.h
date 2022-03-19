#include <opencv2/opencv.hpp>

using namespace cv;


class iConverter {
	public:
		Mat toGray(Mat &img);
		Mat toHSV(Mat &img);
};