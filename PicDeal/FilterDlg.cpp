// FilterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PicDeal.h"
#include "FilterDlg.h"
#include "afxdialogex.h"


// CFilterDlg �Ի���

IMPLEMENT_DYNAMIC(CFilterDlg, CDialogEx)

CFilterDlg::CFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILTERDLG, pParent)
	, m_model(0)
{

}

CFilterDlg::~CFilterDlg()
{
}

void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_model);
	DDV_MinMaxInt(pDX, m_model, 3, 13);
}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialogEx)
END_MESSAGE_MAP()


// CFilterDlg ��Ϣ�������
