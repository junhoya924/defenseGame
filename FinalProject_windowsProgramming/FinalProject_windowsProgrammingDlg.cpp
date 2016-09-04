
// FinalProject_windowsProgrammingDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "FinalProject_windowsProgramming.h"
#include "FinalProject_windowsProgrammingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinalProject_windowsProgrammingDlg 대화 상자




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


// CFinalProject_windowsProgrammingDlg 메시지 처리기

BOOL CFinalProject_windowsProgrammingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFinalProject_windowsProgrammingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFinalProject_windowsProgrammingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFinalProject_windowsProgrammingDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(TRUE);

	if(m_clSecondDlg.DoModal() == IDOK) // 두번째 dlg 호출
	{
		this->rankingFileCopy();
		m_clUser.setId(m_csId);
		m_clThirdDlg.setId(m_csId);

		m_clThirdDlg.DoModal(); // 세번째 dlg 호출
		m_clUser.setScore(m_clThirdDlg.getScore()); // 사용자의 최종 스코어 등록
		m_clUser.setMoney(m_clThirdDlg.getMoney()); // 사용자의 최종 돈 등록
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