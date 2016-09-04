
// FinalProject_windowsProgrammingDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "FinalProject_windowsProgramming.h"
#include "FinalProject_windowsProgrammingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinalProject_windowsProgrammingDlg ��ȭ ����




CFinalProject_windowsProgrammingDlg::CFinalProject_windowsProgrammingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFinalProject_windowsProgrammingDlg::IDD, pParent)
	, m_csId(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	for(int i=0; i<10; i++)
	{
		sRanking[i].iId = 'a';
		sRanking[i].iScore = NULL;
	}
}

void CFinalProject_windowsProgrammingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_csId);
}

BEGIN_MESSAGE_MAP(CFinalProject_windowsProgrammingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CFinalProject_windowsProgrammingDlg �޽��� ó����

BOOL CFinalProject_windowsProgrammingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CFinalProject_windowsProgrammingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CFinalProject_windowsProgrammingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFinalProject_windowsProgrammingDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(TRUE);

	if(m_clSecondDlg.DoModal() == IDOK) // �ι�° dlg ȣ��
	{
		this->rankingFileCopy();
		m_clUser.setId(m_csId);
		m_clThirdDlg.setId(m_csId);

		m_clThirdDlg.DoModal(); // ����° dlg ȣ��
		m_clUser.setScore(m_clThirdDlg.getScore()); // ������� ���� ���ھ� ���
		m_clUser.setMoney(m_clThirdDlg.getMoney()); // ������� ���� �� ���
		this->rankingRegist();

		if(m_clThirdDlg.getExitNum() == 1)
			m_clGameOverDlg.DoModal();
		else if(m_clThirdDlg.getExitNum() == 2)
			m_clVictoryDlg.DoModal();
		
	}
	CDialogEx::OnOK();
}


void CFinalProject_windowsProgrammingDlg::rankingFileCopy()
{
	ifstream ifs;

	ifs.open("ranking.txt");

	for(int i=0; i<10; i++)
	{
		ifs>>sRanking[i].iId;
		ifs>>sRanking[i].iScore;

		if(ifs.eof()==true)
		{
			break;
		}
	}

	ifs.close();
}


void CFinalProject_windowsProgrammingDlg::rankingRegist()
{
	ofstream ofs;
	string stId;
	CT2CA pszConvertedAnsiString(m_csId);
	stId = string(pszConvertedAnsiString);

	ofs.open("ranking.txt");

	int a=0;
	for(int i=0; i<10; i++)
	{
		if(m_clUser.getScore() > sRanking[i].iScore && a == 0)
		{
			ofs << stId <<"   "<< m_clUser.getScore() << endl;
			a++;
		}
		ofs << sRanking[i].iId <<"   "<< sRanking[i].iScore <<endl;

	}

	ofs.close();
}