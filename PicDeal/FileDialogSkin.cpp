// FileDialogSkin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PicDeal.h"
#include "FileDialogSkin.h"

// CFileDialogSkin

IMPLEMENT_DYNAMIC(CFileDialogSkin, CFileDialogSkin)

CFileDialogSkin::CFileDialogSkin(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd, DWORD dwSize, BOOL bVistaStyle) :
		CFileDialogSkin(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd, dwSize, bVistaStyle)
{
	
}

CFileDialogSkin::~CFileDialogSkin()
{
}


BEGIN_MESSAGE_MAP(CFileDialogSkin, CFileDialogSkin)
END_MESSAGE_MAP()



// CFileDialogSkin ��Ϣ�������




BOOL CFileDialogSkin::OnInitDialog()
{
	CFileDialogSkin::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CFileDialogSkin::DestroyWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	return CFileDialogSkin::DestroyWindow();
}
