#include "StdAfx.h"
#include "ShieldUnit5.h"


CShieldUnit5::CShieldUnit5(void)
{
}


CShieldUnit5::~CShieldUnit5(void)
{
}

CShieldUnit5::CShieldUnit5(long locationX, long locationY)
{
	m_corX = locationX;
	m_corY = locationY;
	m_bulletCorX = locationX + 22;
	m_bulletCorY = locationY + 98;
	m_powerAttack = 10;
	m_speedAttack = 30;
	m_bullet = NULL;
	m_money = 100;
	m_sellMoney = m_money/3;
}

void CShieldUnit5::printObject(CDC* MemDC1, CDC* MemDC)
{
	CBrush brush;
	brush.CreateSolidBrush( RGB(3,2,1) );    
	CBrush* oldBrush = MemDC->SelectObject( &brush );


	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(255,255,255);

	CPen NewPen;
	NewPen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT |PS_JOIN_MITER, 0, &lb);         		
	CPen* pOldPen = MemDC->SelectObject(&NewPen);

	MemDC->Rectangle(CRect((m_corX/20)*20, (m_corY/20)*20, (m_corX/20)*20+20, (m_corY/20)*20+20)/*GetRouteRect(i,j)*/);
	NewPen.DeleteObject();
	brush.DeleteObject();

	MemDC->SelectObject( pOldPen );	//예전 펜을 현재 펜으로 한다.
	MemDC->SelectObject( oldBrush );
}

void CShieldUnit5::printBullet(CDC* MemDC1, CDC* MemDC)
{
	if(m_bullet != NULL)
	{
		m_bullet->printObject(MemDC, MemDC1);
	}
}