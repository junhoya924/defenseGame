#include "StdAfx.h"
#include "ShieldUnit3.h"


CShieldUnit3::CShieldUnit3(void)
{
}


CShieldUnit3::~CShieldUnit3(void)
{
}

CShieldUnit3::CShieldUnit3(long locationX, long locationY)
{
	m_corX = locationX;
	m_corY = locationY;
	m_bulletCorX = locationX + 22;
	m_bulletCorY = locationY + 98;
	m_powerAttack = 20;
	m_speedAttack = 10;
	m_bullet = NULL;
	m_money = 60;
	m_sellMoney = m_money/3;
}

void CShieldUnit3::printObject(CDC* MemDC1, CDC* MemDC)
{
	CBrush brush;
	brush.CreateSolidBrush( RGB(50,100,60) );    
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

	MemDC->SelectObject( pOldPen );	//���� ���� ���� ������ �Ѵ�.
	MemDC->SelectObject( oldBrush );
}

void CShieldUnit3::printBullet(CDC* MemDC1, CDC* MemDC)
{
	if(m_bullet != NULL)
	{
		m_bullet->printObject(MemDC, MemDC1);
	}
}