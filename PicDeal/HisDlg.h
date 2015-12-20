#pragma once
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>

#define   WIDTHBYTES(bits) (((bits)+31)/32*4)

// CHisDlg 对话框

class CHisDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHisDlg)

public:
	CHisDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHisDlg();

// 对话框数据
public:
	void drawpic(IplImage* img, unsigned int id);
	void ChangeWndSize(int Width, int Height);
	void SetHisImage(IplImage* HisImg);
	void ChangeSize(UINT nID, int x, int y);
protected:
	IplImage* Img;
	CString FilePathName;
	CRect Init_rect;
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HISDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnsave();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnPaint();
};
