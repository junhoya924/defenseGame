#pragma once
#include "shieldunit.h"
class CShieldUnit4 :
	public CShieldUnit
{
public:
	CShieldUnit4(void);
	~CShieldUnit4(void);
	CShieldUnit4(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// ��ü����Լ�
	void printBullet(CDC* MemDC1, CDC* MemDC);// �Ѿ˰�ü����Լ�
};

