#include "stdafx.h"

extern "C" __declspec(dllexport) void add(IplImage *input_image,IplImage *input_image_logo,IplImage *output_image);
//extern "C" __declspec(dllexport) void compare(IplImage *input_image, IplImage *output_image, int contrast, int brightness);
extern "C" __declspec(dllexport) void facedetect(IplImage *pSrcImage,IplImage *pGrayImage);
extern "C" __declspec(dllexport) void dilib(IplImage * image, IplImage* eqlimage);
extern "C" __declspec(dllexport) void rgb2gray(IplImage * image,IplImage* eqlimage);