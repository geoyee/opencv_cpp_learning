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


Mat iMat::add(Mat &img, int value) {
	 Mat im = copy(img);
	 return im + value;
}


static void callBack(int pos, void* usrdata) {
	Mat im = *(Mat*)usrdata;
	if (im.data) {
		// Mat tmp = add(im, pos);  // BUG: 未回调时im不存在，调用add报错
		Mat tmp = im.clone();
		tmp += pos;
		imshow("trackImage", tmp);
	}
};

void iMat::trackAdd(Mat &img, int max_value) {
	namedWindow("trackImage", WINDOW_AUTOSIZE);
	int current_value = 0;
	imshow("trackImage", img);
	createTrackbar("light:", "trackImage", &current_value, max_value, callBack, &img);
}