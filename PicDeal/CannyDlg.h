#pragma once


// CCannyDlg �Ի���

class CCannyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCannyDlg)

public:
	CCannyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCannyDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CANNY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_threshold1;
	double m_threshold2;
	int m_size;
	BOOL m_prepro;
};
