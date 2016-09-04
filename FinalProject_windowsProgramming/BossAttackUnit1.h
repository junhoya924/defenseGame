#pragma once
#include "attackunit.h"
class CBossAttackUnit1 :
	public CAttackUnit
{
public:
	CBossAttackUnit1(void);
	~CBossAttackUnit1(void);

	void printObject(CDC*, CDC* MemDC);// 객체출력함수
	CBossAttackUnit1(int arrayRoute[][25]);

	void skill(); // 스킬
};

