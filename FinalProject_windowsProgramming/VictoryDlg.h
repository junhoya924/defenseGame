#pragma once
#include "afxwin.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// CVictoryDlg dialog

struct Sranking
{
	string iId;
	int iScore;
};

class CVictoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVictoryDlg)

public:
	CVictoryDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CVictoryDlg();

// Dialog Data
	enum { IDD = IDD_VICTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void registRanking();
	virtual BOOL OnInitDialog();

protected:
	CListBox m_ConRank; // ·©Å· ¸®½ºÆ®
	Sranking sRanking[10];
	

};
