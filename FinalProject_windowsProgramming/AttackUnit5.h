#pragma once
#include "attackunit.h"
class CAttackUnit5 :
	public CAttackUnit
{
public:
	CAttackUnit5(void);
	~CAttackUnit5(void);

	void printObject(CDC*, CDC* MemDC);// ��ü����Լ�
	CAttackUnit5(int arrayRoute[][25]);
};

