#pragma once
#include "shieldunit.h"
class CShieldUnit3 :
	public CShieldUnit
{
public:
	CShieldUnit3(void);
	~CShieldUnit3(void);
	CShieldUnit3(long locationX, long locationY);
	void printObject(CDC* MemDC1, CDC* MemDC);// °´Ã¼Ãâ·ÂÇÔ¼ö
	void printBullet(CDC* MemDC1, CDC* MemDC);// ÃÑ¾Ë°´Ã¼Ãâ·ÂÇÔ¼ö
};

