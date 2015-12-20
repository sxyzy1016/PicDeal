// FileDialogSkin.cpp : 实现文件
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



// CFileDialogSkin 消息处理程序




BOOL CFileDialogSkin::OnInitDialog()
{
	CFileDialogSkin::OnInitDialog();

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL CFileDialogSkin::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	return CFileDialogSkin::DestroyWindow();
}
