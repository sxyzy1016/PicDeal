#pragma once


// CSmoothDlg �Ի���

class CSmoothDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSmoothDlg)

public:
	CSmoothDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSmoothDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMOOTHDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_model;
};
