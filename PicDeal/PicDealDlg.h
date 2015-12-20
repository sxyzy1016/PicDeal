
// PicDealDlg.h : 头文件
//

#pragma once
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>
#include "FreeImage.h"
#include "ImageEnhance.h"
#include "FFT2.h"
#include "testkong.h"

#define   WIDTHBYTES(bits) (((bits)+31)/32*4)

#pragma comment(lib,"FreeImage.lib")
#pragma comment(lib,"ImgeEnhance.lib")
#pragma comment(lib,"FFT2.lib")
#pragma comment(lib,"testkong.lib")

using namespace cv;

// CPicDealDlg 对话框
class CPicDealDlg : public CDialogEx
{
// 构造
public:
	CPicDealDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICDEAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
public:
	void drawpic(IplImage* img, unsigned int id);
	FIBITMAP* loadfiDIB(char* lpszPathName, int flag);
	IplImage* fbp2ipl(FIBITMAP* bitmap);
	void ChangeWndSize(int Width, int Height);
	void ChangeWndSize(CRect rect);
	void ChangeSize(UINT nID, int x, int y);
protected:
	HICON m_hIcon;
	CMenu m_Menu;
	IplImage* Img;
	CString	FilePathName;
	CRect Init_rect, m_rect;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAbort();
	afx_msg void OnOpen();
	
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSave();
	afx_msg void OnClose();
	afx_msg void OnExit();
	afx_msg void OnContrast();
	afx_msg void OnFilter();
	afx_msg void OnAvg();
	afx_msg void OnPsecol();
	afx_msg void OnHistogram();
	afx_msg void OnFft();
	afx_msg void OnRgb2gray();
	afx_msg void OnLaplacesharpness();
	afx_msg void OnEdgedet();
};
