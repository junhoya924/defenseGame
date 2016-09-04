// VictoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalProject_windowsProgramming.h"
#include "VictoryDlg.h"
#include "afxdialogex.h"


// CVictoryDlg dialog

IMPLEMENT_DYNAMIC(CVictoryDlg, CDialogEx)

CVictoryDlg::CVictoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVictoryDlg::IDD, pParent)
{
	for(int i=0; i<10; i++)
	{
		sRanking[i].iId = 'a';
		sRanking[i].iScore = NULL;
	}
}

CVictoryDlg::~CVictoryDlg()
{
}

void CVictoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RANKINGLIST, m_ConRank);
}


BEGIN_MESSAGE_MAP(CVictoryDlg, CDialogEx)
END_MESSAGE_MAP()


// CVictoryDlg message handlers


BOOL CVictoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	this->registRanking();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CVictoryDlg::registRanking()
{
	ifstream ifs;

	ifs.open("ranking.txt");

	for(int i=0; i<10; i++)
	{
		ifs>>sRanking[i].iId;
		ifs>>sRanking[i].iScore;

		if(ifs.eof()==true)
		{
			break;
		}
	}

	ifs.close();

	int i, j;
	i = 0;
	j = 0;

	while(i <10 && j <20)
	{
		CString tempId(sRanking[i].iId.c_str());
		m_ConRank.InsertString(j,tempId);
		tempId.Format(_T("%d"), sRanking[i].iScore);
		j++;
		m_ConRank.InsertString(j, tempId);

		i++;
		j++;
	}

}