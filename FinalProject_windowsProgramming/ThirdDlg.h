#pragma once
#include "AttackUnit1.h"
#include "AttackUnit2.h"
#include "AttackUnit3.h"
#include "AttackUnit4.h"
#include "AttackUnit5.h"
#include "AttackUnit6.h"

#include "ShieldUnit1.h"
#include "ShieldUnit2.h"
#include "ShieldUnit3.h"
#include "ShieldUnit4.h"
#include "ShieldUnit5.h"
#include "ShieldUnit6.h"
#include "BossAttackUnit1.h"
#include "resource.h"
#include <iostream>
#include <fstream>
using namespace std;

#define RouteSize 20
#define MAX_MAP_WIDTH 900/RouteSize
#define MAX_MAP_HEIGHT 500/RouteSize

// CThirdDlg dialog

class CThirdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThirdDlg)

public:
	CThirdDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CThirdDlg();

	int getScore(); // 스코어를 반환한다.
	int getMoney(); // 돈을 반환한다.
	int getExitNum(); // 종료코드를 반환한다.
	void getMap(); // 맵을 가져온다.
	void setId(CString csId); // 아이디를 설정한다.
	
// Dialog Data
	enum { IDD = IDD_THIRD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	int m_backGroundArray[MAX_MAP_WIDTH][MAX_MAP_HEIGHT]; // 배경
	int m_iSecond; // 초
	int m_iMinute; // 분
	int m_iHour; // 시간

	CString m_csTempId; // 사용자 아이디
	int m_iTempScore; // 스코어
	int m_iTempMoney; // 현재 가지고 있는 돈
	CPoint m_mouseCur; // 현재 마우스 위치
	
	CAttackUnit* m_attackUnit; // 공격유닛 임시 포인터
	CShieldUnit* m_shieldUnit; // 방어유닛 임시 포인터
	CList<CAttackUnit*> m_listAttackUnit; // 공격유닛 리스트
	CList<CShieldUnit*> m_listShieldUnit; // 방어유닛 리스트
	bool m_pauseTimer; // 시간의 멈춤을 확인
	int m_exitNum; // 반환코드
	int m_buildingFlag; // 건물 코드
	bool m_isBuilding; // 현재 건설중인지...
	CString m_time; // 시간출력 변수

	DECLARE_MESSAGE_MAP()

	
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	afx_msg void OnBnClickedButtonunit1();
	afx_msg void OnBnClickedButtonunit2();
	afx_msg void OnBnClickedButtonunit3();
	afx_msg void OnBnClickedButtonunit4();
	afx_msg void OnBnClickedButtonunit5();
	afx_msg void OnBnClickedButtonunit6();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtondeleteunit();
	afx_msg void OnBnClickedButtonpause();
	afx_msg void OnBnClickedButtonrestart();
//	virtual void OnCancel();
	afx_msg void OnBnClickedCancel();
};
