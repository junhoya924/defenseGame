#pragma once
#include "shieldunit.h"
class CShieldUnit1 :
	public CShieldUnit
{
public:
	CShieldUnit1(void);
	
	~CShieldUnit1(void);
	CShieldUnit1(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// ��ü����Լ�
	void printBullet(CDC* MemDC1, CDC* MemDC);// �Ѿ˰�ü����Լ�
};

