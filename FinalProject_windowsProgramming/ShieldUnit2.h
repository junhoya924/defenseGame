#pragma once
#include "shieldunit.h"
class CShieldUnit2 :
	public CShieldUnit
{
public:
	CShieldUnit2(void);
	~CShieldUnit2(void);
	CShieldUnit2(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// °´Ã¼Ãâ·ÂÇÔ¼ö
	void printBullet(CDC* MemDC1, CDC* MemDC);// ÃÑ¾Ë°´Ã¼Ãâ·ÂÇÔ¼ö
};

