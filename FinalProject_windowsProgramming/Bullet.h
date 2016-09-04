#pragma once
#include "structobject.h"
class CBullet :
	public CStructObject
{
public:
	CBullet(void);
	~CBullet(void);
	CBullet(long x, long y);
	bool calcPoint(long enemyX, long enemyY, int speed); // 목표의 위치를 받아와 총알이 날아가는 방향을 설정
	void printObject(CDC* MemDC1, CDC* MemDC);// 객체출력함수


};

