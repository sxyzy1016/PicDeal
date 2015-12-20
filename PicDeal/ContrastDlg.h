#pragma once
#include "afxcmn.h"


// CContrastDlg �Ի���

class CContrastDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CContrastDlg)

public:
	CContrastDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CContrastDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTRASTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	double m_contrast;
	double m_light;
	CSliderCtrl m_conctrl;
	CSliderCtrl m_brictrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
};
