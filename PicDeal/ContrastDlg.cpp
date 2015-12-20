// ContrastDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PicDeal.h"
#include "ContrastDlg.h"
#include "afxdialogex.h"


// CContrastDlg 对话框

IMPLEMENT_DYNAMIC(CContrastDlg, CDialogEx)

CContrastDlg::CContrastDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONTRASTDLG, pParent)
	, m_contrast(-0.01)
	, m_light(-0.01)
{

}

CContrastDlg::~CContrastDlg()
{
}

void CContrastDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_conctrl);
	DDX_Control(pDX, IDC_SLIDER2, m_brictrl);
}


BEGIN_MESSAGE_MAP(CContrastDlg, CDialogEx)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CContrastDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CContrastDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CContrastDlg::OnNMCustomdrawSlider2)
END_MESSAGE_MAP()


// CContrastDlg 消息处理程序


//void CContrastDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}


BOOL CContrastDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_conctrl.SetRange(-1, 20);
	m_conctrl.SetTicFreq(0.01);
	m_brictrl.SetRange(-1, 20);
	m_brictrl.SetTicFreq(0.01);
	m_conctrl.SetPos(-1);
	m_brictrl.SetPos(-1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CContrastDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_contrast = m_conctrl.GetPos();
	UpdateData(FALSE);
	*pResult = 0;
}


void CContrastDlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_light = m_brictrl.GetPos();
	UpdateData(FALSE);
	*pResult = 0;
}
