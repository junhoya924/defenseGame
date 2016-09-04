#pragma once


// CSecondDlg dialog

class CSecondDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSecondDlg();

// Dialog Data
	enum { IDD = IDD_SECOND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
