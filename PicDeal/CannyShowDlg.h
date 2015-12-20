#pragma once
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>

#define   WIDTHBYTES(bits) (((bits)+31)/32*4)

// CCannyShowDlg �Ի���

class CCannyShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCannyShowDlg)

public:
	CCannyShowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCannyShowDlg();

// �Ի�������
protected:
	IplImage* Img;
	CString FilePathName;
	CRect Init_rect;
public:
	void drawpic(IplImage* img, unsigned int id);
	void ChangeWndSize(int Width, int Height);
	void SetCannyImage(IplImage* HisImg);
	void ChangeSize(UINT nID, int x, int y);
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CANNYSHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBnsave();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
