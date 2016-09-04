#pragma once
#include "attackunit.h"
class CAttackUnit2 :
	public CAttackUnit
{
public:
	CAttackUnit2(void);
	~CAttackUnit2(void);
	void printObject(CDC*, CDC* MemDC);// 객체출력함수
	CAttackUnit2(int arrayRoute[][25]);
};

