//
//  main.cpp
//  opencvtest
//
//  Created by KatoTakashi on 2016/02/29.
//  Copyright © 2016年 KatoTakashi. All rights reserved.


//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//
//int main(int argc, const char * argv[])
//{
//    cv::Mat img(cv::Size(320, 240), CV_8UC3, cv::Scalar(60, 150, 80));
//    cv::namedWindow("OpenCV3!", cv::WINDOW_AUTOSIZE);
//    cv::imshow("OpenCV3!", img);
//    
//    cv::waitKey(0);
//}


//画像の読み込み
/*
#include "cv.h"
#include "highgui.h"

int main(int argc, const char * argv[]){
    // 画像ファイルポインタの宣言
    IplImage* img;
    // 読み込み画像ファイル名
    char imgfile[] = "/Users/katotakashi/Desktop/lena.jpg";
    
    // 画像の読み込み
    img = cvLoadImage(imgfile, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
    
    // 画像の表示用ウィンドウ生成
    cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);
    
    // 指定したウィンドウ内に画像を表示する
    cvShowImage("lena", img);
    
    // キー入力待ち
    cvWaitKey(0);
    
    // 指定したウィンドウの破棄を行う
    cvDestroyWindow("lena");
    
    // 生成した画像ヘッダ、及びそのデータ領域を解放する
    cvReleaseImage(&img);
    
    return 0;
}
*/


/*
 #include "highgui.h"
 #include "cv.h"
 
 int g_slider_position = 0;
 CvCapture* g_capture = NULL;
 
 void onTrackbarSlide(int pos){
 cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
 }
 
 //映像表示
 //int main(int argc, const char * argv[]){
 //    cvNamedWindow("testAvi", CV_WINDOW_AUTOSIZE);
 //    char imgfile[] = "/Users/katotakashi/Documents/git/study/oepnCVmac/opencvtest/opencvtest/test.mov";
 //    CvCapture* capture = cvCreateFileCapture(imgfile);
 //    IplImage* frame;
 //    while (1) {
 //        frame = cvQueryFrame(capture);
 //        if (!frame)break;
 //
 //        cvShowImage("testAvi", frame);
 //        char c = cvWaitKey(33);
 //        if (c ==27)break;
 //    }
 //    cvReleaseCapture(&capture);
 //    cvDestroyWindow("testAvi");
 //
 //}
 
 int main(int argc, const char * argv[]){
 cvNamedWindow("testAvi", CV_WINDOW_AUTOSIZE);
 char imgfile[] = "/Users/katotakashi/Documents/git/study/oepnCVmac/opencvtest/opencvtest/test.mov";
 g_capture = cvCreateFileCapture(imgfile);
 int frames = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
 if (frames!=0) {
 cvCreateTrackbar("Position", "testAvi", &g_slider_position, frames, onTrackbarSlide);
 }
 
 IplImage* frame;
 while (1) {
 frame = cvQueryFrame(g_capture);
 if (!frame)break;
 
 cvShowImage("testAvi", frame);
 char c = cvWaitKey(33);
 if (c ==27)break;
 }
 cvReleaseCapture(&g_capture);
 cvDestroyWindow("testAvi");
 }
 */

#include "highgui.h"
#include "cv.h"

//cvPryDown()を用いて入力画像の半分の幅と高さを持つ新しい画像を作成する
//IPL_GAUSSIAN_5x5 -> CV_GAUSSIAN_5x5に変更
IplImage* doPyrDown(IplImage* in, int filter = CV_GAUSSIAN_5x5){
    //入力画像が2で割るとベスト
    assert(in->width%2==0 && in->height%2 == 0);
    
    IplImage* out = cvCreateImage(CvSize(in->width/2, in->height/2), in->depth, in->nChannels);
    cvPyrDown(in, out);
    return (out);
};


//Cannyエッジ検出器は出力をシングルチャンネル（グレースケール）の画像に書き込む
IplImage* doCanny(
    IplImage* in,
    double lowThresh,
    double highTresh,
    double aperture
){
    if(in->nChannels !=1)
        return(0); //Cannyはグレースケールの画像だけ扱う
    IplImage* out = cvCreateImage(
                                  cvGetSize(in),
                                  in->depth, //IPL_DEPTH_8U
                                  1);
    cvCanny(in, out, lowThresh, highTresh, aperture);
    return (out);
}

int main(int argc, const char * argv[]){
    // 画像ファイルポインタの宣言
    IplImage* img;
    // 読み込み画像ファイル名
    char imgfile[] = "/Users/katotakashi/Desktop/test1.jpg";
    
    // 画像の読み込み
    img = cvLoadImage(imgfile, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
    
    // 画像の表示用ウィンドウ生成
//    cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("IN");
    cvNamedWindow("OUT");
    
    //平滑化した出力を保持する画像
    IplImage* out = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
    IplImage* in = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
    
    IplImage*image1 = doPyrDown(in, CV_GAUSSIAN_5x5);
    
    //平滑化処理
    cvSmooth(img, out, CV_GAUSSIAN, 3, 3);
    
    // 指定したウィンドウ内に画像を表示する
    cvShowImage("OUT", img);
    
    //片す
    cvReleaseImage(&out);


    
    // キー入力待ち
    cvWaitKey(0);
    
    // 指定したウィンドウの破棄を行う
    cvDestroyWindow("IN");
    cvDestroyWindow("OUT");
    
    // 生成した画像ヘッダ、及びそのデータ領域を解放する
    cvReleaseImage(&img);
    
    return 0;
}




















