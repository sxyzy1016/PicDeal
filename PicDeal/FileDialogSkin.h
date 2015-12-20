#pragma once
#include <Windows.h>

// CFileDialogSkin

class CFileDialogSkin : public CFileDialog
{
	DECLARE_DYNAMIC(CFileDialogSkin)

public:
	CFileDialogSkin(BOOL bOpenFileDialog, // ���� FileOpen Ϊ TRUE������ FileSaveAs Ϊ FALSE
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL,
		DWORD dwSize = 0UL,
		BOOL bVistaStyle = 1);
	virtual ~CFileDialogSkin();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL DestroyWindow();
};


