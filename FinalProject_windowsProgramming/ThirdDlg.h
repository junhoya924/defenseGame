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

	int getScore(); // ���ھ ��ȯ�Ѵ�.
	int getMoney(); // ���� ��ȯ�Ѵ�.
	int getExitNum(); // �����ڵ带 ��ȯ�Ѵ�.
	void getMap(); // ���� �����´�.
	void setId(CString csId); // ���̵� �����Ѵ�.
	
// Dialog Data
	enum { IDD = IDD_THIRD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	int m_backGroundArray[MAX_MAP_WIDTH][MAX_MAP_HEIGHT]; // ���
	int m_iSecond; // ��
	int m_iMinute; // ��
	int m_iHour; // �ð�

	CString m_csTempId; // ����� ���̵�
	int m_iTempScore; // ���ھ�
	int m_iTempMoney; // ���� ������ �ִ� ��
	CPoint m_mouseCur; // ���� ���콺 ��ġ
	
	CAttackUnit* m_attackUnit; // �������� �ӽ� ������
	CShieldUnit* m_shieldUnit; // ������� �ӽ� ������
	CList<CAttackUnit*> m_listAttackUnit; // �������� ����Ʈ
	CList<CShieldUnit*> m_listShieldUnit; // ������� ����Ʈ
	bool m_pauseTimer; // �ð��� ������ Ȯ��
	int m_exitNum; // ��ȯ�ڵ�
	int m_buildingFlag; // �ǹ� �ڵ�
	bool m_isBuilding; // ���� �Ǽ�������...
	CString m_time; // �ð���� ����

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
