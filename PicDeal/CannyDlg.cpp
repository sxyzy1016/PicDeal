// CannyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PicDeal.h"
#include "CannyDlg.h"
#include "afxdialogex.h"


// CCannyDlg 对话框

IMPLEMENT_DYNAMIC(CCannyDlg, CDialogEx)

CCannyDlg::CCannyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CANNY, pParent)
	, m_threshold1(0)
	, m_threshold2(0)
	, m_size(0)
	, m_prepro(FALSE)
{

}

CCannyDlg::~CCannyDlg()
{
}

void CCannyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HOLD1, m_threshold1);
	DDX_Text(pDX, IDC_HOLD2, m_threshold2);
	DDX_Text(pDX, IDC_SIZE, m_size);
	DDX_Check(pDX, IDC_PREPRO, m_prepro);
}


BEGIN_MESSAGE_MAP(CCannyDlg, CDialogEx)
END_MESSAGE_MAP()


// CCannyDlg 消息处理程序
