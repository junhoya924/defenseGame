#pragma once
#include"StructObject.h"

class CAttackUnit
	:public CStructObject
{
public:
	CAttackUnit(void);
	~CAttackUnit(void);

	void move(int arrayRoute[][25]); // 움직임을 담당하는 함수

	void moveLeft(); // 왼쪽으로 움직이는 함수
	void moveRight(); // 오른쪽으로 움직이는 함수
	void moveUp(); // 위로 움직이는 함수
	void moveDown(); // 아래로 움직이는 함수
	int getHp(); // 현재 체력을 반환하는 함수
	void setHp(int hp); // 현재 체력을 설정하는 함수
	char getDirectionChange(); // 움직이는 방향을 반환하는 함수
	virtual void skill(){} // 각 공격유닛의 스킬함수
protected:
	int m_iSpeedMove; // 움직이는 속도
	char m_cDirectionChange; // 지금 움직이고 있는 방향
	
	long m_locationX; // 현재 위치
	long m_locationY;
	int m_hp; // 체력
};

