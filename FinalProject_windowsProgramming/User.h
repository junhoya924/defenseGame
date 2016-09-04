#pragma once
class CUser
{
protected:
	int m_iHaveMoney;
	int m_iScore;
	CString m_csId;

public:
	CUser(void);
	CUser(int haveMoney, int score, CString id); // 생성자
	void setMoney(int iHaveMoney); // 멤버변수 설정함수
	void setScore(int iScore);
	void setId(CString csId);

	int getMoney();// 멤버변수 반환함수
	int getScore();
	CString getId();
	~CUser(void);
};

