#include <opencv2/opencv.hpp>

using namespace cv;


class iDraw {
	public:
		Mat baseDrawDemo(Mat &img);
		void randLineDemo(Size size);
		void polygonDemo();
};