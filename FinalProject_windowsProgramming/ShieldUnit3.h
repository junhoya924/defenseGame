#pragma once
#include "shieldunit.h"
class CShieldUnit3 :
	public CShieldUnit
{
public:
	CShieldUnit3(void);
	~CShieldUnit3(void);
	CShieldUnit3(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// ��ü����Լ�
	void printBullet(CDC* MemDC1, CDC* MemDC);// �Ѿ˰�ü����Լ�
};

