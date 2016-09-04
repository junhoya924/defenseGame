#pragma once
#include "shieldunit.h"
class CShieldUnit6 :
	public CShieldUnit
{
public:
	CShieldUnit6(void);
	~CShieldUnit6(void);
	CShieldUnit6(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// °´Ã¼Ãâ·ÂÇÔ¼ö
	void printBullet(CDC* MemDC1, CDC* MemDC);// ÃÑ¾Ë°´Ã¼Ãâ·ÂÇÔ¼ö
};

