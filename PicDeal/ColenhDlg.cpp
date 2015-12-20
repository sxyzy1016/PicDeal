// ColenhDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PicDeal.h"
#include "ColenhDlg.h"
#include "afxdialogex.h"


// CColenhDlg �Ի���

IMPLEMENT_DYNAMIC(CColenhDlg, CDialogEx)

CColenhDlg::CColenhDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COLENH, pParent)
	, m_group(0)
{

}

CColenhDlg::~CColenhDlg()
{
}

void CColenhDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RGB, m_group);
}


BEGIN_MESSAGE_MAP(CColenhDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RGB, &CColenhDlg::OnBnClickedRgb)
	ON_BN_CLICKED(IDC_RBG, &CColenhDlg::OnBnClickedRbg)
	ON_BN_CLICKED(IDC_BRG, &CColenhDlg::OnBnClickedBrg)
	ON_BN_CLICKED(IDC_GRB, &CColenhDlg::OnBnClickedGrb)
	ON_BN_CLICKED(IDC_GBR, &CColenhDlg::OnBnClickedGbr)
	ON_BN_CLICKED(IDC_BGR, &CColenhDlg::OnBnClickedBgr)
END_MESSAGE_MAP()


// CColenhDlg ��Ϣ�������


void CColenhDlg::OnBnClickedRgb()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_enh = 1;
}


void CColenhDlg::OnBnClickedRbg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_enh = 2;
}


void CColenhDlg::OnBnClickedBrg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_enh = 3;
}


void CColenhDlg::OnBnClickedGrb()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_enh = 4;
}


void CColenhDlg::OnBnClickedGbr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_enh = 5;
}


void CColenhDlg::OnBnClickedBgr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_enh = 6;
}
