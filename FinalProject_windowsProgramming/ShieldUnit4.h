#pragma once
#include "shieldunit.h"
class CShieldUnit4 :
	public CShieldUnit
{
public:
	CShieldUnit4(void);
	~CShieldUnit4(void);
	CShieldUnit4(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// °´Ã¼Ãâ·ÂÇÔ¼ö
	void printBullet(CDC* MemDC1, CDC* MemDC);// ÃÑ¾Ë°´Ã¼Ãâ·ÂÇÔ¼ö
};

