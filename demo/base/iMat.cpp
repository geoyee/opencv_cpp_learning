#include <iostream>
#include <string.h>
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
	return im + value;
}


Mat iMat::iMul(Mat &img, double value) {
	Mat im = iCopy(img);
	im *= value;
	im.convertTo(im, CV_8U);
	return im;
}


static void contrastCallBack(int pos, void* usrdata) {
	iMat m;
	Mat im = *(Mat*)usrdata;
	if (im.data) {
		double alpha = ((double)pos / 250 + 0.8);  // 0.8 - 1.2
		Mat tmp = m.iMul(im, alpha);
		imshow("trackImage", tmp);
		// memcpy(usrdata, (void*)(&tmp), sizeof(Mat));
	}
};

static void lightCallBack(int pos, void* usrdata) {
	iMat m;
	Mat im = *(Mat*)usrdata;
	if (im.data) {
		int beta = pos - 50;  // -50 - 50
		Mat tmp = m.iAdd(im, beta);
		imshow("trackImage", tmp);
		// memcpy(usrdata, (void*)(&tmp), sizeof(Mat));
	}
};

void iMat::trackAdd(Mat &img, int max_alpha, int max_beta) {
	namedWindow("trackImage", WINDOW_AUTOSIZE);
	int current_alpha = 50;
	int current_beta = 50;
	// imshow("trackImage", img);
	// FIXME: 如何不使用全局变量使下面两个操作的结果对应同一张图
	createTrackbar("contrast:", "trackImage", &current_alpha, max_alpha, contrastCallBack, &img);
	createTrackbar("light:", "trackImage", &current_beta, max_beta, lightCallBack, &img);
}