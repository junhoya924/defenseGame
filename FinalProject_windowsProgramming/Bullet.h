#pragma once
#include "structobject.h"
class CBullet :
	public CStructObject
{
public:
	CBullet(void);
	~CBullet(void);
	CBullet(long x, long y);
	bool calcPoint(long enemyX, long enemyY, int speed); // ��ǥ�� ��ġ�� �޾ƿ� �Ѿ��� ���ư��� ������ ����
	void printObject(CDC* MemDC1, CDC* MemDC);// ��ü����Լ�


};

