#pragma once
#include "shieldunit.h"
class CShieldUnit2 :
	public CShieldUnit
{
public:
	CShieldUnit2(void);
	~CShieldUnit2(void);
	CShieldUnit2(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// ��ü����Լ�
	void printBullet(CDC* MemDC1, CDC* MemDC);// �Ѿ˰�ü����Լ�
};

