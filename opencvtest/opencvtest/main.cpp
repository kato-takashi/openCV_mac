//
//  main.cpp
//  opencvtest
//
//  Created by KatoTakashi on 2016/02/29.
//  Copyright © 2016年 KatoTakashi. All rights reserved.


#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, const char * argv[])
{
    cv::Mat img(cv::Size(320, 240), CV_8UC3, cv::Scalar(60, 150, 80));
    cv::namedWindow("OpenCV3!", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV3!", img);
    
    cv::waitKey(0);
}

//
//#include "cv.h"
//#include "highgui.h"
//
//int main(int argc, const char * argv[]){
//    // 画像ファイルポインタの宣言
//    IplImage* img;
//    // 読み込み画像ファイル名
//    char imgfile[] = "/Users/katotakashi/Desktop/lena.jpg";
//    
//    // 画像の読み込み
//    img = cvLoadImage(imgfile, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
//    
//    // 画像の表示用ウィンドウ生成
//    cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);
//    
//    // 指定したウィンドウ内に画像を表示する
//    cvShowImage("lena", img);
//    
//    // キー入力待ち
//    cvWaitKey(0);
//    
//    // 指定したウィンドウの破棄を行う
//    cvDestroyWindow("lena");
//    
//    // 生成した画像ヘッダ、及びそのデータ領域を解放する
//    cvReleaseImage(&img);
//    
//    return 0;
//}