#include <iostream>
#include <opencv2/opencv.hpp>
#include "iTransform.h"

using namespace std;
using namespace cv;


Mat iTransform::iNormal(Mat &img) {
	Mat im = img.clone();
	double max_val, min_val;
	im.convertTo(im, CV_32FC3);
	minMaxIdx(im, &min_val, &max_val);
	cout << "raw: [" << min_val << ", " << max_val << "]\n";
	normalize(im, im, 1.0, 0, NORM_MINMAX);
	minMaxIdx(im, &min_val, &max_val);
	cout << "normal: [" << min_val << ", " << max_val << "]\n";
	return im;
}


vector<Mat> iTransform::iResize(Mat &img) {
	Mat zoom_in, zoom_out;
	vector<Mat> mats;
	int h = img.rows;
	int w = img.cols;
	resize(img, zoom_in, Size(w / 2, h / 2), 0, 0, INTER_LINEAR);
	resize(img, zoom_out, Size(), 2, 2, INTER_CUBIC);
	mats.push_back(zoom_in);
	mats.push_back(zoom_out);
	return mats;
}


Mat iTransform::iHFlip(Mat &img) {
	Mat hf_im;
	flip(img, hf_im, 1);
	return hf_im;
}


Mat iTransform::iRotate(Mat &img, double ang, bool keep) {
	Mat ro_im;
	int h = img.rows;
	int w = img.cols;
	Mat M = getRotationMatrix2D(Point2f(w / 2, h / 2), ang, 1.0);
	if (keep){
		double cos = M.at<double>(0, 0);
		double sin = M.at<double>(0, 1);
		double nh = sin * w + cos * h;
		double nw = cos * w + sin * h;
		M.at<double>(0, 2) += (nw / 2 - (double)w / 2);
		M.at<double>(1, 2) += (nh / 2 - (double)h / 2);
		warpAffine(img, ro_im, M, Size(int(nw), int(nh)), INTER_CUBIC, 0, Scalar(7, 242, 220));
	}
	else {
		warpAffine(img, ro_im, M, img.size(), INTER_CUBIC, 0, Scalar(7, 242, 220));
	}
	return ro_im;
}