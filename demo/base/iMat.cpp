#include <iostream>
#include "iMat.h"

using namespace std;


Mat iMat::copy(Mat &img) {
	return img.clone();
}


Mat iMat::constValue(Size size, int value) {
	Mat const_mat = Mat::ones(size, CV_8U);
	const_mat = Scalar(value);
	return const_mat;
}


void iMat::showInfo(Mat &img) {
	cout << "wight: " << img.cols << " height: " << img.rows << " channels: " << img.channels() << endl;
}


Mat iMat::ergodicInv(Mat &img) {
	Mat im = copy(img);
	int H = img.rows;
	int W = img.cols;
	int C = img.channels();
	for (int row = 0; row < H; row++) {
		for (int col = 0; col < W; col++) {
			if (C == 1) {
				int current_pix = im.at<uchar>(row, col);
				im.at<uchar>(row, col) = 255 - current_pix;
			}
			if (C == 3) {
				Vec3d current_bgr = im.at<Vec3d>(row, col);
				im.at<Vec3d>(row, col) = Vec3d(255) - current_bgr;
			}
		}
	}
	return im;
}


Mat iMat::ergodicInv2(Mat& img) {
	Mat im = copy(img);
	int H = img.rows;
	int W = img.cols;
	int C = img.channels();
	for (int row = 0; row < H; row++) {
		uchar* current_row = im.ptr<uchar>(row);
		for (int col = 0; col < W; col++) {
			if (C == 1) {
				int current_pix = *current_row;
				*current_row++ = 255 - current_pix;
			}
			if (C == 3) {
				for (int i = 0; i < 3; i++) {
					*current_row++ = 255 - *current_row;
				}
			}
		}
	}
	return im;
}