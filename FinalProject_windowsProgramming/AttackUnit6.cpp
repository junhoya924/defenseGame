#include "StdAfx.h"
#include "AttackUnit6.h"


CAttackUnit6::CAttackUnit6(void)
{
}


CAttackUnit6::~CAttackUnit6(void)
{
}

CAttackUnit6::CAttackUnit6(int arrayRoute[][25])
{
	m_corX = 20+22;
	m_corY = 459+83;
	m_locationX = 20;
	m_locationY = 459;
	m_hp = 400;
	m_money = 12;
}

void CAttackUnit6::printObject(CDC* MemDC1, CDC* MemDC)
{
    CBrush brush;
    brush.CreateSolidBrush( RGB(255,255,255) );     // 오렌지색 채움색을 생성
    CBrush* oldBrush = MemDC1->SelectObject( &brush );
    MemDC1->Ellipse(m_corX-22, m_corY-98, m_corX+15-22, m_corY+15-98);
    MemDC1->SelectObject( oldBrush );
}
