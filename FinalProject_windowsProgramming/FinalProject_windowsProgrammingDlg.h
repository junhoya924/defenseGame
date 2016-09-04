
// FinalProject_windowsProgrammingDlg.h : ��� ����
//

#pragma once
#include"SecondDlg.h"
#include"ThirdDlg.h"
#include"User.h"
#include"GameOverDlg.h"
#include"VictoryDlg.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;



// CFinalProject_windowsProgrammingDlg ��ȭ ����
class CFinalProject_windowsProgrammingDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CFinalProject_windowsProgrammingDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FINALPROJECT_WINDOWSPROGRAMMING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
	void rankingFileCopy();
	void rankingRegist();

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	
	CUser m_clUser; // �����
	CString m_csId; // ����� ���̵�
	Sranking sRanking[10]; // ��ŷ�� �����ϴ� ����
	CSecondDlg m_clSecondDlg;// �ι�° ���̾�α�
	CThirdDlg m_clThirdDlg; // ����° ���̾�α�
	CVictoryDlg m_clVictoryDlg; // �¸��� ���̾�α�
	CGameOverDlg m_clGameOverDlg; // �й�� ���̾�α�
};
