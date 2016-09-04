#pragma once
#include "structobject.h"
#include "Bullet.h"
#include "AttackUnit.h"
class CShieldUnit :
	public CStructObject
{
public:
	CShieldUnit(void);
	~CShieldUnit(void);

	void attack(long enemyX, long enemyY, CList<CAttackUnit*>*listAttackUnit, int& money, int& score);
	
	virtual void printBullet(CDC* MemDC1, CDC* MemDC){};// 객체출력함수
	void deleteBullet(); // 총알을 지운다.
	bool hasBullet(); // 현재 총알이 있는지 알아보는 함수
	int sell(); // 타워 파는 함수

protected:
	int m_powerAttack; // 타워 공격력
	int m_speedAttack; // 타워 공격 빠르기
	int m_sellMoney; // 타워 팔때 값
	long m_bulletCorX; // 총알의 위치
	long m_bulletCorY;

	CBullet* m_bullet; // 총알
	
};

