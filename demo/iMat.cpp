#include <iostream>
#include "iMat.h"

using namespace std;


Mat iMat::iCopy(Mat &img) {
	return img.clone();
}


Mat iMat::constValue(Size size, int value) {
	Mat const_mat = Mat::ones(size, CV_8U);
	const_mat = Scalar(value);
	return const_mat;
}


void iMat::showInfo(Mat &img) {
	cout << "wight: " << img.cols << " height: " << img.rows << " channels: " << img.channels() << endl;
	vector<Mat> chans;
	split(img, chans);
	double max_c, min_c;
	Point max_loc, min_loc;
	Mat mean_c, std_c;
	for (int i = 0; i < chans.size(); i++) {
		minMaxLoc(chans[i], &min_c, &max_c, &min_loc, &max_loc);
		cout << "channel_" << i << ": min: " << min_c << " max: " << max_c << endl;
	}
	meanStdDev(img, mean_c, std_c);
	cout << "mean: \n" << mean_c << "\nstd: \n" << std_c << endl;
}


Mat iMat::ergodicInv(Mat &img) {
	Mat im = iCopy(img);
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


Mat iMat::ergodicInv2(Mat &img) {
	Mat im = iCopy(img);
	int H = img.rows;
	int W = img.cols;
	int C = img.channels();
	for (int row = 0; row < H; row++) {
		uchar* current_row = im.ptr<uchar>(row);
		for (int col = 0; col < W; col++) {
			if (C == 1) {
				*current_row++ = 255 - *current_row;
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


Mat iMat::iAdd(Mat &img, int value) {
	Mat im = iCopy(img);
	int C = im.channels();
	if (C == 1) {
		return im + value;
	}
	if (C == 3) {
		return im + Scalar(value, value, value);
	}
}


Mat iMat::iMul(Mat &img, double value) {
	Mat im = iCopy(img);
	int C = im.channels();
	if (C == 1) {
		multiply(im, value, im);
	}
	if (C == 3) {
		multiply(im, Scalar(value, value, value), im);
	}
	im.convertTo(im, CV_8U);
	return im;
}