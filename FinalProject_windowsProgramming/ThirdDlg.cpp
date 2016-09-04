// ThirdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalProject_windowsProgramming.h"
#include "ThirdDlg.h"
#include "afxdialogex.h"


// CThirdDlg dialog

IMPLEMENT_DYNAMIC(CThirdDlg, CDialogEx)

CThirdDlg::CThirdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThirdDlg::IDD, pParent)
	, m_time(_T(""))
{
	m_iSecond = 1; // 시간을 초기화
	m_iMinute = 0;
	m_iHour = 0;

	m_iTempScore = 0; // 스코어 초기화
	m_iTempMoney = 600; // 가지고 있는 돈 초기화
}

CThirdDlg::~CThirdDlg()
{
}

void CThirdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITTIME, m_time);
	DDX_Text(pDX, IDC_EDITMONEY, m_iTempMoney);
	DDX_Text(pDX, IDC_EDITSCORE, m_iTempScore);
	DDX_Text(pDX, IDC_EDITID, m_csTempId);
}


BEGIN_MESSAGE_MAP(CThirdDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTONUNIT1, &CThirdDlg::OnBnClickedButtonunit1)
	ON_BN_CLICKED(IDC_BUTTONUNIT2, &CThirdDlg::OnBnClickedButtonunit2)
	ON_BN_CLICKED(IDC_BUTTONUNIT3, &CThirdDlg::OnBnClickedButtonunit3)
	ON_BN_CLICKED(IDC_BUTTONUNIT4, &CThirdDlg::OnBnClickedButtonunit4)
	ON_BN_CLICKED(IDC_BUTTONUNIT5, &CThirdDlg::OnBnClickedButtonunit5)
	ON_BN_CLICKED(IDC_BUTTONUNIT6, &CThirdDlg::OnBnClickedButtonunit6)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTONDELETEUNIT, &CThirdDlg::OnBnClickedButtondeleteunit)
	ON_BN_CLICKED(IDC_BUTTONPAUSE, &CThirdDlg::OnBnClickedButtonpause)
	ON_BN_CLICKED(IDC_BUTTONRESTART, &CThirdDlg::OnBnClickedButtonrestart)
	ON_BN_CLICKED(IDCANCEL, &CThirdDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CThirdDlg message handlers

int CThirdDlg::getScore()
{
	return m_iTempScore + m_iTempMoney * 2;
}

void CThirdDlg::setId(CString csId)
{
	m_csTempId = csId;
}

int CThirdDlg::getMoney()
{
	return m_iTempMoney;
}

int CThirdDlg::getExitNum()
{
	return m_exitNum;
}

void CThirdDlg::getMap()
{
	ifstream ifs;

	ifs.open("route.txt");
	for(int i=0; i<MAX_MAP_HEIGHT; i++)
	{
		for(int j=0; j<MAX_MAP_WIDTH; j++)
		{
			ifs>>m_backGroundArray[j][i];
		}
	}
	ifs.close();
}

void CThirdDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	CDC MemDC;
	CDC MemDC1;

	MemDC.CreateCompatibleDC(&dc);
	MemDC1.CreateCompatibleDC(&dc);

	CBitmap backGround;
	backGround.LoadBitmapW(IDB_BG);
	MemDC.SelectObject(&backGround);

	if(m_isBuilding == 1)
	{
		CBitmap Grid;
		Grid.LoadBitmapW(IDB_GRID);
		MemDC1.SelectObject(Grid);
		MemDC.TransparentBlt(0,0,900,500,&MemDC1,0,0,900,500,RGB(255,0,254));
	}

	for(int i=0;i<MAX_MAP_WIDTH;i++)
	{
		for(int j=0;j<MAX_MAP_HEIGHT;j++)
		{
			if(m_backGroundArray[i][j]==2)
			{
				LOGBRUSH lb;
				lb.lbStyle = BS_SOLID;
				lb.lbColor = RGB(255,255,255);

				CPen NewPen;
				NewPen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT |PS_JOIN_MITER, 0, &lb);         
				CPen* pOldPen = MemDC.SelectObject(&NewPen);

				MemDC.Rectangle(CRect(i*RouteSize, j*RouteSize, i*RouteSize+RouteSize, j*RouteSize+RouteSize));
				NewPen.DeleteObject();
				MemDC.SelectObject(pOldPen);	//예전 펜을 현재 펜으로 한다.
			}
		}
	}
	POSITION cur;
	cur = m_listShieldUnit.GetHeadPosition();

	while(cur)
	{
		m_listShieldUnit.GetNext(cur)->printObject(&MemDC1, &MemDC);
	}

	cur = m_listAttackUnit.GetHeadPosition();

	while(cur)
	{
		m_listAttackUnit.GetNext(cur)->printObject(&MemDC, &MemDC1);
	}

	if(m_isBuilding)
	{
		CBrush brush;
		brush.CreateSolidBrush( RGB(255,50,0) );    
		CBrush* oldBrush = MemDC1.SelectObject( &brush );


		LOGBRUSH lb;
		lb.lbStyle = BS_SOLID;
		lb.lbColor = RGB(255,0,0);

		CPen NewPen;
		NewPen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT |PS_JOIN_MITER, 1, &lb);         
		//선 속성 설정, 굵기 3의 색은 빨간색인 실선, 끝부분 처리는 뾰족함.
		CPen* pOldPen = MemDC1.SelectObject(&NewPen);
		MemDC1.Rectangle(CRect(0,0,RouteSize,RouteSize)/*GetRouteRect(i,j)*/);
		MemDC.StretchBlt(m_mouseCur.x-30,m_mouseCur.y-110,RouteSize,RouteSize,&MemDC1,0,0,RouteSize,RouteSize, SRCCOPY);
		NewPen.DeleteObject();
		brush.DeleteObject();
		MemDC1.SelectObject(pOldPen);	//예전 펜을 현재 펜으로 한다.
		MemDC1.SelectObject( oldBrush );
	}

	cur = m_listShieldUnit.GetHeadPosition();


	while(cur && m_listShieldUnit.GetHead()->hasBullet())
	{
		m_listShieldUnit.GetNext(cur)->printBullet(&MemDC1, &MemDC);
	}

	dc.StretchBlt(22,98,900,500,&MemDC,0,0,900,500,SRCCOPY);  // 비트맵을 화면에 출력
	
}


BOOL CThirdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_pauseTimer = FALSE;
	getMap();
	m_buildingFlag = NULL;
	m_isBuilding = FALSE;

	SetTimer(1000,1000,NULL);
	SetTimer(45,45,NULL);

	

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CThirdDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	POSITION cur;
	if(m_pauseTimer)
	{
		KillTimer(1000);
		KillTimer(45);
	}else
	{
		switch(nIDEvent)
		{
		case 1000:
			if(m_iSecond == 60)
			{
				m_iSecond = 0;
				m_iMinute++;
			}
			if(m_iMinute == 60)
			{
				m_iMinute = 0;
				m_iHour++;
			}
			m_time.Format(L"%d 시간 %d 분 %d 초", m_iHour , m_iMinute, m_iSecond++);

			if(m_iSecond < 15 && m_iMinute < 1)
			{
				m_attackUnit = new CAttackUnit1(m_backGroundArray);
				m_listAttackUnit.AddTail(m_attackUnit);
			}else if(m_iSecond > 20 && m_iSecond < 50 && m_iMinute == 0)
			{
				m_attackUnit = new CAttackUnit2(m_backGroundArray);

				m_listAttackUnit.AddTail(m_attackUnit);
			}else if(m_iSecond < 15 && m_iMinute == 1)
			{
				m_attackUnit = new CAttackUnit3(m_backGroundArray);

				m_listAttackUnit.AddTail(m_attackUnit);
			}else if(m_iSecond > 20 && m_iSecond < 50 && m_iMinute == 1)
			{
				m_attackUnit = new CAttackUnit4(m_backGroundArray);

				m_listAttackUnit.AddTail(m_attackUnit);
			}else if(m_iSecond < 15 && m_iMinute == 2)
			{
				m_attackUnit = new CAttackUnit5(m_backGroundArray);

				m_listAttackUnit.AddTail(m_attackUnit);
			}else if(m_iSecond > 20 && m_iSecond < 50 && m_iMinute == 2)
			{
				m_attackUnit = new CAttackUnit6(m_backGroundArray);

				m_listAttackUnit.AddTail(m_attackUnit);
			}
			else if(m_iMinute == 3 && m_iSecond == 0 || m_iSecond==1 || m_iSecond==30)
			{
				m_attackUnit = new CBossAttackUnit1(m_backGroundArray);

				m_listAttackUnit.AddTail(m_attackUnit);
			}else if(m_iMinute > 3 && m_iSecond < 10)
			{
				m_attackUnit = new CBossAttackUnit1(m_backGroundArray);

				m_listAttackUnit.AddTail(m_attackUnit);
			}else if(m_iMinute > 5&&m_listAttackUnit.GetCount()==0)
			{
				m_exitNum = 2;
				OnBnClickedCancel();
			}

			
			cur = m_listAttackUnit.GetHeadPosition();
			while(cur)
			{
				m_listAttackUnit.GetNext(cur)->skill();
			}

			break;
		case 45:
			
			cur = m_listAttackUnit.GetHeadPosition();
			while(cur)
			{
				m_listAttackUnit.GetNext(cur)->move(m_backGroundArray);
			}

			if(m_listAttackUnit.GetCount()!=NULL)
			{
				if((m_listAttackUnit.GetHead()->getDirectionChange()=='s'))
				{
					delete m_listAttackUnit.GetHead();
					m_listAttackUnit.RemoveHead();
					m_exitNum=1;
					OnBnClickedCancel();
				}
			}

			cur = m_listShieldUnit.GetHeadPosition();
			if(m_listAttackUnit.GetCount() != NULL)
			{
				while(cur && (m_listAttackUnit.GetCount() !=  NULL))
				{
					m_listShieldUnit.GetNext(cur)->attack(m_listAttackUnit.GetHead()->getX(), m_listAttackUnit.GetHead()->getY(), &m_listAttackUnit, m_iTempMoney, m_iTempScore);
				}

			}


			if(m_listAttackUnit.GetCount() == NULL && (m_listShieldUnit.IsEmpty() == false))
			{
				cur = m_listShieldUnit.GetHeadPosition();
				while(cur)
				{
					m_listShieldUnit.GetNext(cur)->deleteBullet();
				}
			}

			break;
		}
	}

	this->Invalidate(0);
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}


void CThirdDlg::OnBnClickedButtonunit1()
{
	// TODO: Add your control notification handler code here
	m_shieldUnit = new CShieldUnit1(0, 0);
	if(m_isBuilding == FALSE && m_iTempMoney >= m_shieldUnit->getMoney())
	{
		m_buildingFlag = 1;
		m_isBuilding = 1;
	}
	delete m_shieldUnit;
}


void CThirdDlg::OnBnClickedButtonunit2()
{
	// TODO: Add your control notification handler code here
	m_shieldUnit = new CShieldUnit2(0, 0);
	if(m_isBuilding == FALSE && m_iTempMoney >= m_shieldUnit->getMoney())
	{
		m_buildingFlag = 2;
		m_isBuilding = 1;
	}
	delete m_shieldUnit;
}


void CThirdDlg::OnBnClickedButtonunit3()
{
	// TODO: Add your control notification handler code here
	m_shieldUnit = new CShieldUnit3(0, 0);
	if(m_isBuilding == FALSE && m_iTempMoney >= m_shieldUnit->getMoney())
	{
		m_buildingFlag = 3;
		m_isBuilding = 1;
	}
	delete m_shieldUnit;
}


void CThirdDlg::OnBnClickedButtonunit4()
{
	// TODO: Add your control notification handler code here
	m_shieldUnit = new CShieldUnit4(0, 0);
	if(m_isBuilding == FALSE && m_iTempMoney >= m_shieldUnit->getMoney())
	{
		m_buildingFlag = 4;
		m_isBuilding = 1;
	}
	delete m_shieldUnit;
}


void CThirdDlg::OnBnClickedButtonunit5()
{
	// TODO: Add your control notification handler code here
	m_shieldUnit = new CShieldUnit5(0, 0);
	if(m_isBuilding == FALSE && m_iTempMoney >= m_shieldUnit->getMoney())
	{
		m_buildingFlag = 5;
		m_isBuilding = 1;
	}
	delete m_shieldUnit;
}


void CThirdDlg::OnBnClickedButtonunit6()
{
	// TODO: Add your control notification handler code here
	m_shieldUnit = new CShieldUnit6(0, 0);
	if(m_isBuilding == FALSE && m_iTempMoney >= m_shieldUnit->getMoney())
	{
		m_buildingFlag = 6;
		m_isBuilding = 1;
	}
	delete m_shieldUnit;
}


void CThirdDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_mouseCur = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CThirdDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CPoint pt=point-CPoint(22,98);
	if(pt.x>=0 && pt.x <= MAX_MAP_WIDTH * RouteSize)
	{
		if(pt.y >=0 && pt.y <= MAX_MAP_HEIGHT * RouteSize)
		{
			if(m_isBuilding==1 && m_backGroundArray[pt.x/20][pt.y/20]==0)
			{
				switch(m_buildingFlag)
				{
				case 1:
					m_shieldUnit = new CShieldUnit1(pt.x, pt.y);
					break;
				case 2:
					m_shieldUnit = new CShieldUnit2(pt.x, pt.y);
					break;
				case 3:
					m_shieldUnit = new CShieldUnit3(pt.x, pt.y);
					break;
				case 4:
					m_shieldUnit = new CShieldUnit4(pt.x, pt.y);
					break;
				case 5:
					m_shieldUnit = new CShieldUnit5(pt.x, pt.y);
					break;
				case 6:
					m_shieldUnit = new CShieldUnit6(pt.x, pt.y);
					break;
				default:
					break;
				}

				if(m_iTempMoney >= m_shieldUnit->getMoney())
				{
					m_backGroundArray[pt.x/20][pt.y/20]=1;
					m_listShieldUnit.AddTail(m_shieldUnit);
					m_iTempMoney -= m_shieldUnit->getMoney();
					
				}else
				{
					delete m_shieldUnit;
				}
				m_buildingFlag = 0;
				m_isBuilding = false;
			}
		}
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CThirdDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CPoint pt = point - CPoint(22,98);
	POSITION temp;
	POSITION cur;
	if(pt.x>=0 && pt.x <= MAX_MAP_WIDTH * RouteSize)
	{
		if(pt.y >=0 && pt.y <= MAX_MAP_HEIGHT * RouteSize)
		{

			if(m_backGroundArray[pt.x/20][pt.y/20]==1)
			{
				cur = m_listShieldUnit.GetHeadPosition();

				while(cur)
				{
					temp = cur;
					if( m_listShieldUnit.GetNext(cur)->getX()/20 == (pt.x)/20
						&&m_listShieldUnit.GetAt(temp)->getY()/20 == (pt.y)/20)
					{
						m_listShieldUnit.GetAt(temp)->deleteBullet();

						m_iTempMoney += m_listShieldUnit.GetAt(temp)->getMoney();
						delete m_listShieldUnit.GetAt(temp);
						m_listShieldUnit.RemoveAt(temp);

						m_backGroundArray[pt.x/20][pt.y/20]=0;

						break;
					}
				}
				
			}
		}
	}
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CThirdDlg::OnBnClickedButtondeleteunit()
{
	// TODO: Add your control notification handler code here
	POSITION cur;

	if(m_iTempMoney >= 300)
	{
		m_iTempMoney -= 300;
		if(m_listAttackUnit.GetCount()!=NULL)
		{
			cur = m_listAttackUnit.GetHeadPosition();
			while(cur)
			{
				POSITION temp = cur;
				delete m_listAttackUnit.GetNext(cur);
				m_listAttackUnit.RemoveAt(temp);

			}
		}
	}
}


void CThirdDlg::OnBnClickedButtonpause()
{
	// TODO: Add your control notification handler code here
	m_pauseTimer = TRUE;
}


void CThirdDlg::OnBnClickedButtonrestart()
{
	// TODO: Add your control notification handler code here
	m_pauseTimer = FALSE;
	SetTimer(1000,1000,NULL);
	SetTimer(45,45,NULL);
}


//void CThirdDlg::OnCancel()
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	CDialogEx::OnCancel();
//}


void CThirdDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
