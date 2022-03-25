#include <iostream>
#include <opencv2/opencv.hpp>
#include "iHist.h"

using namespace std;
using namespace cv;


void iHist::showHist(Mat &img) {
	const int h_max[1] = { 256 };
	float minmax[2] = { 0, 255 };
	const float* ranges[1] = { minmax };
	Mat hist_map = Mat::zeros(Size(512, 512), CV_8UC3);
	int h = img.rows;
	int num_c = img.channels();
	for (int c = 0; c < num_c; c++) {
		Mat hist;
		const int idx[] = { c };
		calcHist(&img, 1, idx, Mat(), hist, 1, h_max, ranges);
		normalize(hist, hist, 0, h, NORM_MINMAX);
		Scalar color = Scalar(0, 0, 0);
		color[c] = 255;
		int interval = cvRound(512.0 / h_max[0]);
		for (int i = 1; i < h_max[0]; i++) {
			Point start = Point(interval * (i - 1), 512 - cvRound(hist.at<float>(i - 1)));
			Point end = Point(interval * i, 512 - cvRound(hist.at<float>(i)));
			line(hist_map, start, end, color);
		}
	}
	imshow("HIST", hist_map);
	waitKey(0);
	destroyAllWindows();
}


void iHist::showHist2D(Mat &img) {
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	const int bins[2] = { 64, 64 };
	float h_minmax[2] = { 0, 180 };
	float s_minmax[2] = { 0, 255 };
	const float* ranges[2] = { h_minmax, s_minmax };
	int bands[2] = { 0, 1 };
	int scale = 10;
	Mat hist;
	double max_val = 0;
	Mat hist_map_2d = Mat::zeros(Size(bins[0] * scale, bins[1] * scale), CV_8UC3);
	calcHist(&img, 1, bands, Mat(), hist, 2, bins, ranges);
	minMaxLoc(hist, 0, &max_val, 0, 0);
	for (int h = 0; h < bins[0]; h++) {
		for (int s = 0; s < bins[1]; s++) {
			float bin_val = hist.at<float>(h, s);
			int intensity = cvRound((double)bin_val * 255 / max_val);
			Point p1 = Point(h * scale, s * scale);
			Point p2 = Point((h + 1) * scale, (s + 1) * scale);
			rectangle(hist_map_2d, p1, p2, Scalar::all(intensity), -1);
		}
	}
	applyColorMap(hist_map_2d, hist_map_2d, COLORMAP_JET);
	imshow("HIST2D", hist_map_2d);
	waitKey(0);
	destroyAllWindows();
}


Mat iHist::histEQ(Mat &img) {
	Mat hsv, result;
	vector<Mat> bands;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	split(hsv, bands);
	equalizeHist(bands[2], bands[2]);
	merge(bands, result);
	cvtColor(result, result, COLOR_HSV2BGR);
	return result;
}