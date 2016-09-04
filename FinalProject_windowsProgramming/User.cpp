#include "StdAfx.h"
#include "User.h"


CUser::CUser(void)
{
	m_iHaveMoney = 0;
	m_iScore = 0;
}


CUser::~CUser(void)
{
}

CUser::CUser(int haveMoney, int score, CString id)
{
	m_iHaveMoney = haveMoney;
	m_iScore = score;
	m_csId = id;
}

void CUser::setMoney(int iHaveMoney) // ������� �����Լ�
{
	m_iHaveMoney = iHaveMoney;
}
void CUser::setScore(int iScore)
{
	m_iScore = iScore;
}
void CUser::setId(CString csId)
{
	m_csId = csId;
}

int CUser::getMoney()// ������� ��ȯ�Լ�
{
	return m_iHaveMoney;
}
int CUser::getScore()
{
	return m_iScore;
}
CString CUser::getId()
{
	return m_csId;
}