#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include "iDeepFace.h"

using namespace std;
using namespace cv;
using namespace dnn;


Mat iDeepFace::det(Mat &img) {
	string root_dir = "E:/dataFiles/github/opencv_cpp_learning/assets/models/FaceDet/";
	Net net = readNetFromTensorflow(
		root_dir + "opencv_face_detector_uint8.pb",
		root_dir + "opencv_face_detector.pbtxt"
	);
	// resize(img, img, Size(300, 300));
	Mat im = img.clone();
	Mat blob = blobFromImage(img, 1.0, Size(300, 300), Scalar(104, 177, 123), false, false);
	net.setInput(blob);
	Mat preds = net.forward();
	Mat det_mat = Mat(preds.size[2], preds.size[3], CV_32F, preds.ptr<float>());
	for (int i = 0; i < det_mat.rows; i++) {
		float conf = det_mat.at<float>(i, 2);
		if (conf > 0.5) {
			int x1 = static_cast<int>(det_mat.at<float>(i, 3) * img.cols);
			int y1 = static_cast<int>(det_mat.at<float>(i, 4) * img.rows);
			int x2 = static_cast<int>(det_mat.at<float>(i, 5) * img.cols);
			int y2 = static_cast<int>(det_mat.at<float>(i, 6) * img.rows);
			Rect box = Rect(Point(x1, y1), Point(x2, y2));
			rectangle(im, box, Scalar(0, 0, 255));
		}
	}
	return im;
}