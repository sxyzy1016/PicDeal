#include "stdafx.h"
extern "C" __declspec(dllexport)void outfft(IplImage *src,IplImage *Image,IplImage *ImageDst);
extern "C" __declspec(dllexport)void rotation(IplImage *img,IplImage *pImgRotation);
extern "C" __declspec(dllexport)void lapulasi(IplImage* Image,IplImage* NewImage);