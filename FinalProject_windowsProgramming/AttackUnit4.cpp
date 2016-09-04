#include "StdAfx.h"
#include "AttackUnit4.h"


CAttackUnit4::CAttackUnit4(void)
{
}


CAttackUnit4::~CAttackUnit4(void)
{
}

CAttackUnit4::CAttackUnit4(int arrayRoute[][25])
{
	m_corX = 20+22;
	m_corY = 459+83;
	m_locationX = 20;
	m_locationY = 459;
	m_hp = 220;
	m_money = 6;
}

void CAttackUnit4::printObject(CDC* MemDC1, CDC* MemDC)
{
    CBrush brush;
    brush.CreateSolidBrush( RGB(0,50,200) );
    CBrush* oldBrush = MemDC1->SelectObject( &brush );
    MemDC1->Ellipse(m_corX-22, m_corY-98, m_corX+15-22, m_corY+15-98);
    MemDC1->SelectObject( oldBrush );
}
