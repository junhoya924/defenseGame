#include "StdAfx.h"
#include "ShieldUnit.h"


CShieldUnit::CShieldUnit(void)
{
}


CShieldUnit::~CShieldUnit(void)
{
}

int CShieldUnit::sell()
{
	return m_sellMoney;
}

void CShieldUnit::attack(long enemyX, long enemyY, CList<CAttackUnit*>*listAttackUnit, int& money, int& score)
{
	if(m_bullet == NULL)
	{
		m_bullet= new CBullet(m_bulletCorX,m_bulletCorY);
	}

	if(listAttackUnit->IsEmpty()==false)
	{
		if( !m_bullet->calcPoint(enemyX, enemyY, m_speedAttack))
		{
			int temp = (listAttackUnit->GetHead()->getHp());
			temp = temp - m_powerAttack;
			listAttackUnit->GetHead()->setHp(temp);
			if(listAttackUnit->GetHead()->getHp() <= 0)
			{
				money += listAttackUnit->GetHead()->getMoney();
				score += listAttackUnit->GetHead()->getMoney() * 10;
				delete listAttackUnit->GetHead();
				listAttackUnit->RemoveHead();
			}
			delete m_bullet;
			m_bullet = NULL;
		}
	}
}

void CShieldUnit::deleteBullet()
{
	if(m_bullet != NULL)
	{
		delete m_bullet;
		m_bullet = NULL;
	}
}

bool CShieldUnit::hasBullet()
{
	if(m_bullet != NULL)
	{
		return TRUE;
	}
	return FALSE;
}