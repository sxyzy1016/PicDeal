#include "stdafx.h"


extern "C" __declspec(dllexport) void Smooth(IplImage* Image,IplImage* NewIamge,int Hight,int with);
extern "C" __declspec(dllexport) void MiddleFiltering(IplImage* Image,IplImage* NewIamge,int Hight,int with);
extern "C" __declspec(dllexport) void ColorEnhancement(IplImage* Image,IplImage* NewImage,char* color);
extern "C" __declspec(dllexport) void mcvCanny(IplImage* pImage,IplImage* pNewImage,double threshold1,double threshold2, int aperture_size=3, bool preprocessing=false);
extern "C" __declspec(dllexport) IplImage* compare(IplImage* Input,int contrast,int brightness);