#pragma once
#include "attackunit.h"
class CBossAttackUnit1 :
	public CAttackUnit
{
public:
	CBossAttackUnit1(void);
	~CBossAttackUnit1(void);

	void printObject(CDC*, CDC* MemDC);// ��ü����Լ�
	CBossAttackUnit1(int arrayRoute[][25]);

	void skill(); // ��ų
};

