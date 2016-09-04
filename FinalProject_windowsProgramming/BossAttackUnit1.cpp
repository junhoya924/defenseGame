#include "StdAfx.h"
#include "BossAttackUnit1.h"


CBossAttackUnit1::CBossAttackUnit1(void)
{
}


CBossAttackUnit1::~CBossAttackUnit1(void)
{
}

CBossAttackUnit1::CBossAttackUnit1(int arrayRoute[][25])
{
	m_corX = 20 + 22;
	m_corY = 459 + 83;
	m_locationX = 20;
	m_locationY = 459;
	m_hp = 1500;
	m_money = 50;
	//move(arrayRoute);
}

void CBossAttackUnit1::skill()
{
	m_hp += 200; // 시간마다 체력을 늘려준다.(timer와 연동)
}

void CBossAttackUnit1::printObject(CDC* MemDC1, CDC* MemDC)
{
    CBrush brush;
    brush.CreateSolidBrush( RGB(255,128,0) );     
    CBrush* oldBrush = MemDC1->SelectObject( &brush );
    MemDC1->Ellipse(m_corX-22, m_corY-98, m_corX+15-22, m_corY+15-98);
    MemDC1->SelectObject( oldBrush );
}
