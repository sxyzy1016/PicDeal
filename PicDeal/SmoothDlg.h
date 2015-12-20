#pragma once


// CSmoothDlg 对话框

class CSmoothDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSmoothDlg)

public:
	CSmoothDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSmoothDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMOOTHDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_model;
};
