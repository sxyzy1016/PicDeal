
// PicDeal.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPicDealApp: 
// �йش����ʵ�֣������ PicDeal.cpp
//

class CPicDealApp : public CWinApp
{
public:
	CPicDealApp();
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CPicDealApp theApp;