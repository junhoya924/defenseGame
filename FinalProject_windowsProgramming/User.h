#pragma once
class CUser
{
protected:
	int m_iHaveMoney;
	int m_iScore;
	CString m_csId;

public:
	CUser(void);
	CUser(int haveMoney, int score, CString id); // ������
	void setMoney(int iHaveMoney); // ������� �����Լ�
	void setScore(int iScore);
	void setId(CString csId);

	int getMoney();// ������� ��ȯ�Լ�
	int getScore();
	CString getId();
	~CUser(void);
};

