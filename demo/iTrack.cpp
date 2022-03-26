#include <string.h>
#include "iMat.h"
#include "iTrack.h"


// static void contrastCallBack(int pos, void* usrdata) {
// 	 iMat m;
// 	 Mat im = *(Mat*)usrdata;
// 	 if (im.data) {
// 		 double alpha = ((double)pos / 250 + 0.8);  // 0.8 - 1.2
// 		 Mat tmp = m.iMul(im, alpha);
// 		 imshow("trackImage", tmp);
// 		 // memcpy(usrdata, (void*)(&tmp), sizeof(Mat));
// 	 }
// };
// 
// static void lightCallBack(int pos, void* usrdata) {
// 	 iMat m;
// 	 Mat im = *(Mat*)usrdata;
// 	 if (im.data) {
//		 int beta = pos - 50;  // -50 - 50
//		 Mat tmp = m.iAdd(im, beta);
//		 imshow("trackImage", tmp);
//		 // memcpy(usrdata, (void*)(&tmp), sizeof(Mat));
//	 }
// };
//
// void iTrack::trackAdd(Mat &img, int max_alpha, int max_beta) {
//	 namedWindow("trackImage", WINDOW_AUTOSIZE);
//	 int current_alpha = 50;
//	 int current_beta = 50;
//	 // imshow("trackImage", img);
//	 // FIXME: 如何不使用全局变量使下面两个操作的结果对应同一张图
//	 createTrackbar("contrast:", "trackImage", &current_alpha, max_alpha, contrastCallBack, &img);
//	 createTrackbar("light:", "trackImage", &current_beta, max_beta, lightCallBack, &img);
//	 waitKey(0);
//	 destroyAllWindows();
// }


Mat usr_img;
int contrast_value = 50;
int light_value = 50;

static void clShow() {
	iMat m;
	if (usr_img.data) {
		double alpha = ((double)contrast_value / 250 + 0.8);  // 0.8 - 1.2
		int beta = light_value - 50;  // -50 - 50
		Mat tmp = usr_img.clone();
		tmp = m.iMul(tmp, alpha);
		tmp = m.iAdd(tmp, beta);
		imshow("trackImage", tmp);
	}
};

static void contrastCallBack(int pos, void* usrdata) {
	contrast_value = pos;
	clShow();
};

static void lightCallBack(int pos, void* usrdata) {
	light_value = pos;
	clShow();
};

void iTrack::trackAdd(Mat &img, int max_alpha, int max_beta) {
	usr_img = img;
	namedWindow("trackImage", WINDOW_AUTOSIZE);
	int current_alpha = contrast_value;
	int current_beta = light_value;
	createTrackbar("contrast:", "trackImage", &current_alpha, max_alpha, contrastCallBack);
	createTrackbar("light:", "trackImage", &current_beta, max_beta, lightCallBack);
	waitKey(0);
	destroyAllWindows();
}