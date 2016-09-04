// GameOverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalProject_windowsProgramming.h"
#include "GameOverDlg.h"
#include "afxdialogex.h"


// CGameOverDlg dialog

IMPLEMENT_DYNAMIC(CGameOverDlg, CDialogEx)

CGameOverDlg::CGameOverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameOverDlg::IDD, pParent)
{
	for(int i=0; i<10; i++)
	{
		sRanking[i].iId='a';
		sRanking[i].iScore = NULL;
	}
}

CGameOverDlg::~CGameOverDlg()
{
}

void CGameOverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_conList);
}


BEGIN_MESSAGE_MAP(CGameOverDlg, CDialogEx)
END_MESSAGE_MAP()


// CGameOverDlg message handlers



BOOL CGameOverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	this->registRanking();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CGameOverDlg::registRanking()
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
		m_conList.InsertString(j,tempId);
		tempId.Format(_T("%d"), sRanking[i].iScore);
		j++;
		m_conList.InsertString(j, tempId);

		i++;
		j++;
	}

}