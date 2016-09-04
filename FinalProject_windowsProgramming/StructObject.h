#pragma once
#include<string>
#include<iostream>
using namespace std;

class CStructObject
{
public:
	CStructObject(void);
	~CStructObject(void);
	virtual void printExplanation(){}; 
	virtual void printObject(CDC* MemDC1, CDC* MemDC){};
	long getX(); // ��ġ�� ��ȯ�Ѵ�.
	long getY(); 
	int getMoney(); // ���� ��ȯ�Ѵ�.
protected:
	string m_name; // �̸�
	string m_explanation; // ����
	int m_money;// ��
	long m_corX;//��ġ
	long m_corY;
};

