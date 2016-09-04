
// FinalProject_windowsProgrammingDlg.h : 헤더 파일
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



// CFinalProject_windowsProgrammingDlg 대화 상자
class CFinalProject_windowsProgrammingDlg : public CDialogEx
{
// 생성입니다.
public:
	CFinalProject_windowsProgrammingDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FINALPROJECT_WINDOWSPROGRAMMING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	void rankingFileCopy();
	void rankingRegist();

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	
	CUser m_clUser; // 사용자
	CString m_csId; // 사용자 아이디
	Sranking sRanking[10]; // 랭킹을 관리하는 변수
	CSecondDlg m_clSecondDlg;// 두번째 다이얼로그
	CThirdDlg m_clThirdDlg; // 세번째 다이얼로그
	CVictoryDlg m_clVictoryDlg; // 승리시 다이얼로그
	CGameOverDlg m_clGameOverDlg; // 패배시 다이얼로그
};
