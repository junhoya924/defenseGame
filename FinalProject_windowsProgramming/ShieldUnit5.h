#pragma once
#include "shieldunit.h"
class CShieldUnit5 :
	public CShieldUnit
{
public:
	CShieldUnit5(void);
	~CShieldUnit5(void);
	CShieldUnit5(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// ��ü����Լ�
	void printBullet(CDC* MemDC1, CDC* MemDC);// �Ѿ˰�ü����Լ�
};

