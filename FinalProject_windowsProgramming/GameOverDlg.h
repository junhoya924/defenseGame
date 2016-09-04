#pragma once
#include "afxwin.h"
#include"VictoryDlg.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// CGameOverDlg dialog



class CGameOverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameOverDlg)

public:
	CGameOverDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGameOverDlg();

// Dialog Data
	enum { IDD = IDD_GAMEOVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	void registRanking();

protected:
	CListBox m_conList; // ����Ʈ�ڽ� ����
	Sranking sRanking[10]; // ��ŷ�� ������ �ִ� ����
};
