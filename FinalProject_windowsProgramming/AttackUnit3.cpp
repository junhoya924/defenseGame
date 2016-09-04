#include "StdAfx.h"
#include "AttackUnit3.h"


CAttackUnit3::CAttackUnit3(void)
{
}


CAttackUnit3::~CAttackUnit3(void)
{
}

CAttackUnit3::CAttackUnit3(int arrayRoute[][25])
{
	m_corX = 20+22;
	m_corY = 459+83;
	m_locationX = 20;
	m_locationY = 459;
	m_hp = 150;
	m_money = 5;
}

void CAttackUnit3::printObject(CDC* MemDC1, CDC* MemDC)
{
    CBrush brush;
    brush.CreateSolidBrush( RGB(50,50,0) );
    CBrush* oldBrush = MemDC1->SelectObject( &brush );
    MemDC1->Ellipse(m_corX-22, m_corY-98, m_corX+20-22, m_corY+20-98);
    MemDC1->SelectObject( oldBrush );
}
