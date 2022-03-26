#include <opencv2/opencv.hpp>

using namespace cv;


class iTrack {
	public:
		void trackAdd(Mat &img, int max_alpha=100, int max_beta=100);
};