#pragma once
#include"StructObject.h"

class CAttackUnit
	:public CStructObject
{
public:
	CAttackUnit(void);
	~CAttackUnit(void);

	void move(int arrayRoute[][25]); // �������� ����ϴ� �Լ�

	void moveLeft(); // �������� �����̴� �Լ�
	void moveRight(); // ���������� �����̴� �Լ�
	void moveUp(); // ���� �����̴� �Լ�
	void moveDown(); // �Ʒ��� �����̴� �Լ�
	int getHp(); // ���� ü���� ��ȯ�ϴ� �Լ�
	void setHp(int hp); // ���� ü���� �����ϴ� �Լ�
	char getDirectionChange(); // �����̴� ������ ��ȯ�ϴ� �Լ�
	virtual void skill(){} // �� ���������� ��ų�Լ�
protected:
	int m_iSpeedMove; // �����̴� �ӵ�
	char m_cDirectionChange; // ���� �����̰� �ִ� ����
	
	long m_locationX; // ���� ��ġ
	long m_locationY;
	int m_hp; // ü��
};

