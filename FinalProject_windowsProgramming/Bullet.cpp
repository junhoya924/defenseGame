#include "StdAfx.h"
#include "Bullet.h"


CBullet::CBullet(void)
{
}


CBullet::CBullet(long x, long y)
{
	m_corX = x;
	m_corY = y;
	
}

CBullet::~CBullet(void)
{
}

bool CBullet::calcPoint(long enemyX, long enemyY, int speed)
{
	CPoint vector;
	vector.x = enemyX - m_corX;
	vector.y = enemyY - m_corY;

	double tempX;
	double tempY;

	tempX = (double)((vector.x)*(vector.x)); // 벡터 계산 식
	tempY = (double)((vector.y)*(vector.y));

	double length;

	length = sqrt(tempX+tempY);
	
	if((abs(enemyX - m_corX)>10) || (abs(enemyY - m_corY))>10) // 목표에 닿였는지 확인
	{
		m_corX += (LONG)((speed*vector.x)/length);
		m_corY += (LONG)((speed*vector.y)/length);
		return true;
	}else
	{
		return false;
	}


}

void CBullet::printObject(CDC* MemDC1, CDC* MemDC)
{
	CBrush brush;
    brush.CreateSolidBrush( RGB(255,0,255) );   
    CBrush* oldBrush = MemDC1->SelectObject( &brush );
    MemDC1->Ellipse(m_corX - 22, m_corY - 98, m_corX + 10 - 22, m_corY + 10 - 98);
    MemDC1->SelectObject( oldBrush );
}