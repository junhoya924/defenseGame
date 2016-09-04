#pragma once
#include "shieldunit.h"
class CShieldUnit5 :
	public CShieldUnit
{
public:
	CShieldUnit5(void);
	~CShieldUnit5(void);
	CShieldUnit5(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// °´Ã¼Ãâ·ÂÇÔ¼ö
	void printBullet(CDC* MemDC1, CDC* MemDC);// ÃÑ¾Ë°´Ã¼Ãâ·ÂÇÔ¼ö
};

