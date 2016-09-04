#include "StdAfx.h"
#include "AttackUnit5.h"


CAttackUnit5::CAttackUnit5(void)
{
}


CAttackUnit5::~CAttackUnit5(void)
{
}

CAttackUnit5::CAttackUnit5(int arrayRoute[][25])
{
	m_corX = 20+22;
	m_corY = 459+83;
	m_locationX = 20;
	m_locationY = 459;
	m_hp = 250;
	m_money = 8;
}

void CAttackUnit5::printObject(CDC* MemDC1, CDC* MemDC)
{
    CBrush brush;
    brush.CreateSolidBrush( RGB(0,0,0) );     // 오렌지색 채움색을 생성
    CBrush* oldBrush = MemDC1->SelectObject( &brush );
    MemDC1->Ellipse(m_corX-22, m_corY-98, m_corX+15-22, m_corY+15-98);
    MemDC1->SelectObject( oldBrush );
}
