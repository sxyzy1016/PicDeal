#pragma once


// CColenhDlg �Ի���

class CColenhDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CColenhDlg)

public:
	CColenhDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CColenhDlg();

// �Ի�������
public:
	int m_enh;
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLENH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_group;
	afx_msg void OnBnClickedRgb();
	afx_msg void OnBnClickedRbg();
	afx_msg void OnBnClickedBrg();
	afx_msg void OnBnClickedGrb();
	afx_msg void OnBnClickedGbr();
	afx_msg void OnBnClickedBgr();
};
