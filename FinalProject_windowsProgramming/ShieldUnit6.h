#pragma once
#include "shieldunit.h"
class CShieldUnit6 :
	public CShieldUnit
{
public:
	CShieldUnit6(void);
	~CShieldUnit6(void);
	CShieldUnit6(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// ��ü����Լ�
	void printBullet(CDC* MemDC1, CDC* MemDC);// �Ѿ˰�ü����Լ�
};

