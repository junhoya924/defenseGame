#pragma once
#include"AttackUnit.h"

class CAttackUnit1
	:public CAttackUnit
{
public:
	CAttackUnit1(void);
	~CAttackUnit1(void);
	CAttackUnit1(int arrayroute[][25]);
	void printObject(CDC* MemDC1, CDC* MemDC); // 객체출력함수
};

