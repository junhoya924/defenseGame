#pragma once
#include "attackunit.h"
class CAttackUnit5 :
	public CAttackUnit
{
public:
	CAttackUnit5(void);
	~CAttackUnit5(void);

	void printObject(CDC*, CDC* MemDC);// 객체출력함수
	CAttackUnit5(int arrayRoute[][25]);
};

