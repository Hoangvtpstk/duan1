
// tien_ich_sinh_tetsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "tien_ich_sinh_tets.h"
#include "tien_ich_sinh_tetsDlg.h"
#include "afxdialogex.h"
#include<io.h>
#include"tao_thu_muc.h"
#include <windows.h>
#include<fstream>
#include<time.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtienichsinhtetsDlg dialog



CtienichsinhtetsDlg::CtienichsinhtetsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIEN_ICH_SINH_TETS_DIALOG, pParent)
	, ten_TM(_T(""))
	, soluong(0)
	, batdau(0)
	
	, ketthuc(0)
	, input(_T(""))
	, output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtienichsinhtetsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEN_TM, ten_TM);
	DDX_Text(pDX, IDC_SLT, soluong);
	DDX_Text(pDX, IDC_EDIT3, batdau);
	DDX_Text(pDX, IDC_EDIT4, input);
	DDX_Text(pDX, IDC_EDIT5, output);
}

BEGIN_MESSAGE_MAP(CtienichsinhtetsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_TEN_TM, &CtienichsinhtetsDlg::OnEnChangeTenTm)
	
	ON_BN_CLICKED(IDC_BUTTON1, &CtienichsinhtetsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtienichsinhtetsDlg message handlers

BOOL CtienichsinhtetsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CtienichsinhtetsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CtienichsinhtetsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CtienichsinhtetsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtienichsinhtetsDlg::OnEnChangeTenTm()
{
	
}
  


void CtienichsinhtetsDlg::OnBnClickedButton1()
{
	CString path;
	CString path_add;
	CString path_foder;
	tao_thu_muc   tenthumuc;
	tao_thu_muc   tenthumuctest;
	CString path_file_in;

	// tao thu muc cha
		UpdateData(TRUE);
		path = _T("D:\\Code\\tien_ich_sinh_tets\\sinhtest\\");
		tenthumuc.taoTM((path+ten_TM));


	for (int i = batdau; i < soluong+batdau; i++) {

		//tao thu muc test
		path_add.Format(_T("%d"), i);
		path_foder = ten_TM + "\\" + ten_TMTEST + path_add;	
		tenthumuctest.taoTMTEST(path + path_foder);

		// sinh file iuput
		CString path_file_in = path + path_foder + "\\" + input;
		ofstream taoinput;
		taoinput.open(path_file_in);

		//sinh file output
		CString path_file_out = path + path_foder + "\\" + output;
		ofstream taooutput;
		taooutput.open(path_file_out);
	}
	
}
