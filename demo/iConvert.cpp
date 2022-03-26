#include <iostream>
#include "iConvert.h"
#include "iMat.h"

using namespace std;


Mat iConverter::toGray(Mat &img) {
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	return gray;
}


Mat iConverter::toHSV(Mat &img) {
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	return hsv;
}


int I_COLOR_MAP[] = {
	COLORMAP_AUTUMN,
	COLORMAP_BONE,
	COLORMAP_CIVIDIS,
	COLORMAP_COOL,
	COLORMAP_DEEPGREEN,
	COLORMAP_HOT,
	COLORMAP_HSV,
	COLORMAP_INFERNO,
	COLORMAP_JET,
	COLORMAP_MAGMA,
	COLORMAP_OCEAN,
	COLORMAP_PARULA,
	COLORMAP_PINK,
	COLORMAP_PLASMA,
	COLORMAP_RAINBOW,
	COLORMAP_SPRING,
	COLORMAP_SUMMER,
	COLORMAP_TURBO,
	COLORMAP_TWILIGHT,
	COLORMAP_TWILIGHT_SHIFTED,
	COLORMAP_VIRIDIS,
	COLORMAP_WINTER
};


void iConverter::colorShow(Mat &img) {
	Mat tmp = img.clone();
	int idx = 0;
	int lenght = sizeof(I_COLOR_MAP) / sizeof(I_COLOR_MAP[0]);
	while (true)
	{
		if ((int)waitKey(200) == 27) {
			// destroyAllWindows();
			break;
		}
		applyColorMap(img, tmp, I_COLOR_MAP[idx % lenght]);
		idx++;
		cout << idx << endl;
		imshow("Converter", tmp);
	}
}


void iConverter::keyConverter(Mat &img) {
	iMat m;
	Mat c_img = img;
	while (true)
	{
		int c = waitKey(0);
		cout << c << endl;
		switch (c) {
			case 114:  // R
				c_img = img;
				break;
			case 103:  // G
				c_img = toGray(img);
				break;
			case 104:  // H
				c_img = toHSV(img);
				break;
			case 105:  // I
				c_img = m.ergodicInv2(img);
				break;
			case 99:  // color
				colorShow(img);  // ESCÍË³ö
				break;
			case 27:  // ESC
				destroyAllWindows();
				return;
		}
		imshow("Converter", c_img);
	}
}


Mat iConverter::splitAndMerge(Mat &img) {
	Mat dst;
	vector<Mat> chans;
	split(img, chans);
	chans[0] = chans[1];
	merge(chans, dst);
	int fromTo[] = { 0, 1, 1, 2, 2, 0 };
	mixChannels(&img, 1, &dst, 1, fromTo, 3);
	return dst;
}


Mat iConverter::inRangGreen(Mat &img) {
	Mat hsv = toHSV(img);
	Mat mask;
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
	return mask;
}