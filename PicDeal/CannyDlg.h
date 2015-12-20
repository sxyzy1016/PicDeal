#pragma once


// CCannyDlg 对话框

class CCannyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCannyDlg)

public:
	CCannyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCannyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CANNY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_threshold1;
	double m_threshold2;
	int m_size;
	BOOL m_prepro;
};
