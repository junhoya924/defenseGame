#pragma once
#include "attackunit.h"
class CAttackUnit6 :
	public CAttackUnit
{
public:
	CAttackUnit6(void);
	~CAttackUnit6(void);

	void printObject(CDC*, CDC* MemDC);// ��ü����Լ�
	CAttackUnit6(int arrayRoute[][25]);
};

