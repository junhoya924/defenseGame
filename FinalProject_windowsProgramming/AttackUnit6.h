#pragma once
#include "attackunit.h"
class CAttackUnit6 :
	public CAttackUnit
{
public:
	CAttackUnit6(void);
	~CAttackUnit6(void);

	void printObject(CDC*, CDC* MemDC);// 객체출력함수
	CAttackUnit6(int arrayRoute[][25]);
};

