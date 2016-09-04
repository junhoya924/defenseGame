#include "StdAfx.h"
#include "AttackUnit.h"


CAttackUnit::CAttackUnit(void)
{
}


CAttackUnit::~CAttackUnit(void)
{
}

void CAttackUnit::move(int arrayRoute[][25])
{
	if(arrayRoute[m_locationX/20+1][m_locationY/20] == 2)
	{
		m_cDirectionChange='r';
	}else if(arrayRoute[m_locationX/20][m_locationY/20-1] == 2)
	{
		m_cDirectionChange='u';
	}else if(arrayRoute[m_locationX/20][m_locationY/20+1] == 2)
	{
		m_cDirectionChange='d';
	}else if(arrayRoute[m_locationX/20-1][m_locationY/20] == 2)
	{
		m_cDirectionChange='l';
	}
	

	if((m_locationX/20==24) && (m_locationY/20>=18) && (m_locationY/20<=21)
		|| (m_locationX/20==36) && (m_locationY/20>=1) && (m_locationY/20<=22)
		|| (m_locationX/20==14))
	{
		m_cDirectionChange='d';

		if((m_locationY/20==22))
		{
			m_cDirectionChange='r';
		}
	}


	if((m_locationX/20<=28) && (m_locationY/20==8) && (m_locationX/20>=19))
	{
		m_cDirectionChange='l';
	}
	if((m_locationX/20==19) && ((m_locationY/20)<=8) && ((m_locationY/20)>=2))
	{
		m_cDirectionChange='u';
	}
	
	if((m_locationX/20==44) && ((m_locationY/20)==13))
	{
		m_cDirectionChange='s';
	}
	
	switch(m_cDirectionChange)
	{
	case 'u':
		moveUp();
		break;
	case 'r':
		moveRight();
		break;
	case 'd':
		moveDown();
		break;
	case 'l':
		moveLeft();
		break;
	case 's':
		break;
	}
}


void CAttackUnit::moveLeft()
{
	m_corX-=3;
	m_locationX-=3;
}
void CAttackUnit::moveRight()
{
	m_corX+=3;
	m_locationX+=3;
}
void CAttackUnit::moveUp()
{
	m_corY-=3;
	m_locationY-=3;
}
void CAttackUnit::moveDown()
{
	m_corY+=3;
	m_locationY+=3;
}

int CAttackUnit::getHp()
{
	return this->m_hp;
}

void CAttackUnit::setHp(int hp)
{
	m_hp = hp;
}

char CAttackUnit::getDirectionChange()
{
	return this->m_cDirectionChange;
}