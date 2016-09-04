#pragma once
#include "attackunit.h"
class CAttackUnit3 :
	public CAttackUnit
{
public:
	CAttackUnit3(void);
	~CAttackUnit3(void);
	void printObject(CDC*, CDC* MemDC);// 객체출력함수
	CAttackUnit3(int arrayRoute[][25]);
};

