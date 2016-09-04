#include "StdAfx.h"
#include "ShieldUnit4.h"


CShieldUnit4::CShieldUnit4(void)
{
}


CShieldUnit4::~CShieldUnit4(void)
{
}

CShieldUnit4::CShieldUnit4(long locationX, long locationY)
{
	m_corX = locationX;
	m_corY = locationY;
	m_bulletCorX = locationX + 22;
	m_bulletCorY = locationY + 98;
	m_powerAttack = 80;
	m_speedAttack = 5;
	m_bullet = NULL;
	m_money = 70;
	m_sellMoney = m_money/3;
}

void CShieldUnit4::printObject(CDC* MemDC1, CDC* MemDC)
{
	CBrush brush;
	brush.CreateSolidBrush( RGB(0,28,287) );    
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

void CShieldUnit4::printBullet(CDC* MemDC1, CDC* MemDC)
{
	if(m_bullet != NULL)
	{
		m_bullet->printObject(MemDC, MemDC1);
	}
}