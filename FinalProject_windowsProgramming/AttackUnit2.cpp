#include "StdAfx.h"
#include "AttackUnit2.h"


CAttackUnit2::CAttackUnit2(void)
{
}


CAttackUnit2::~CAttackUnit2(void)
{
}

CAttackUnit2::CAttackUnit2(int arrayRoute[][25])
{
	m_corX = 20+22;
	m_corY = 459+83;
	m_locationX = 20;
	m_locationY = 459;
	m_hp = 60;
	m_money = 4;
}

void CAttackUnit2::printObject(CDC* MemDC1, CDC* MemDC)
{
    CBrush brush;
    brush.CreateSolidBrush( RGB(255,100,25) );     
    CBrush* oldBrush = MemDC1->SelectObject( &brush );
    MemDC1->Ellipse(m_corX-22, m_corY-98, m_corX+15-22, m_corY+15-98);
    MemDC1->SelectObject( oldBrush );
}
