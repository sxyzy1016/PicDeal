// SmoothDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PicDeal.h"
#include "SmoothDlg.h"
#include "afxdialogex.h"


// CSmoothDlg 对话框

IMPLEMENT_DYNAMIC(CSmoothDlg, CDialogEx)

CSmoothDlg::CSmoothDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SMOOTHDLG, pParent)
	, m_model(0)
{

}

CSmoothDlg::~CSmoothDlg()
{
}

void CSmoothDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_model);
	DDV_MinMaxInt(pDX, m_model, 3, 13);
}


BEGIN_MESSAGE_MAP(CSmoothDlg, CDialogEx)
END_MESSAGE_MAP()


// CSmoothDlg 消息处理程序
