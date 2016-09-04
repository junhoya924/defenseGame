#pragma once
#include "attackunit.h"
class CAttackUnit4 :
	public CAttackUnit
{
public:
	CAttackUnit4(void);
	~CAttackUnit4(void);
	void printObject(CDC*, CDC* MemDC);// 객체출력함수
	CAttackUnit4(int arrayRoute[][25]);
};

