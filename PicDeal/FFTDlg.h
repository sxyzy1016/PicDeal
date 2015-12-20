#pragma once
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>

#define   WIDTHBYTES(bits) (((bits)+31)/32*4)

// CFFTDlg �Ի���

class CFFTDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFFTDlg)

public:
	CFFTDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFFTDlg();

// �Ի�������
public:
	void drawpic(IplImage* img, unsigned int id);
	void ChangeWndSize(int Width, int Height);
	void SetFFTImage(IplImage* HisImg);
	void ChangeSize(UINT nID, int x, int y);
protected:
	CString FilePathName;
	IplImage* Img;
	CRect Init_rect;
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FFTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnsave();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
};
