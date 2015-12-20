#pragma once
#include <Windows.h>

// CFileDialogSkin

class CFileDialogSkin : public CFileDialog
{
	DECLARE_DYNAMIC(CFileDialogSkin)

public:
	CFileDialogSkin(BOOL bOpenFileDialog, // 对于 FileOpen 为 TRUE，对于 FileSaveAs 为 FALSE
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


