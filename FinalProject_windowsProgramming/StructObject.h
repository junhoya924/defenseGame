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
	long getX(); // 위치를 반환한다.
	long getY(); 
	int getMoney(); // 돈을 반환한다.
protected:
	string m_name; // 이름
	string m_explanation; // 설명
	int m_money;// 돈
	long m_corX;//위치
	long m_corY;
};

