
// FinalProject_windowsProgramming.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFinalProject_windowsProgrammingApp:
// �� Ŭ������ ������ ���ؼ��� FinalProject_windowsProgramming.cpp�� �����Ͻʽÿ�.
//

class CFinalProject_windowsProgrammingApp : public CWinApp
{
public:
	CFinalProject_windowsProgrammingApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFinalProject_windowsProgrammingApp theApp;