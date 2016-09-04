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
	
	virtual void printBullet(CDC* MemDC1, CDC* MemDC){};// ��ü����Լ�
	void deleteBullet(); // �Ѿ��� �����.
	bool hasBullet(); // ���� �Ѿ��� �ִ��� �˾ƺ��� �Լ�
	int sell(); // Ÿ�� �Ĵ� �Լ�

protected:
	int m_powerAttack; // Ÿ�� ���ݷ�
	int m_speedAttack; // Ÿ�� ���� ������
	int m_sellMoney; // Ÿ�� �ȶ� ��
	long m_bulletCorX; // �Ѿ��� ��ġ
	long m_bulletCorY;

	CBullet* m_bullet; // �Ѿ�
	
};

