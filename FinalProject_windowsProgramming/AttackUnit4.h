#pragma once
#include "attackunit.h"
class CAttackUnit4 :
	public CAttackUnit
{
public:
	CAttackUnit4(void);
	~CAttackUnit4(void);
	void printObject(CDC*, CDC* MemDC);// ��ü����Լ�
	CAttackUnit4(int arrayRoute[][25]);
};

