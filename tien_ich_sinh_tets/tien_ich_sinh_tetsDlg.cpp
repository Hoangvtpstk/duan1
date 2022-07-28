
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
#include"sinh_file_input.h"
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
public:
	
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
	, ten_TM(_T("test"))
	, soluong(10)
	, batdau(1)
	
	, ketthuc(5)
	, input(_T("a.inp"))
	, output(_T("b.out"))
	, rand_batdau(0)
	, rand_ketthuc(50)
	, tes_bd_1(1)
	, tes_kt_1(5)

	, test_bd_2(6)
	, test_kt_2(10)
	, rand_bd_1(50)
	, rand_kt_1(100)
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
	DDX_Text(pDX, IDC_EDIT6, rand_batdau);
	DDX_Text(pDX, IDC_EDIT7, rand_ketthuc);
	DDX_Text(pDX, IDC_EDIT8, tes_bd_1);
	DDX_Text(pDX, IDC_EDIT9, tes_kt_1);

	DDX_Control(pDX, IDC_COMBO1, m_chon_chuong_trinh);
	DDX_Control(pDX, IDC_COMBO2, kieu_du_lieu);

	DDX_Text(pDX, IDC_EDIT11, test_bd_2);
	DDX_Text(pDX, IDC_EDIT12, test_kt_2);
	DDX_Text(pDX, IDC_EDIT13, rand_bd_1);
	DDX_Text(pDX, IDC_EDIT14, rand_kt_1);
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

	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//add gia tri vao bien lua chon
	m_chon_chuong_trinh.AddString(_T("Tạo một giá trị"));
	m_chon_chuong_trinh.AddString(_T("Tạo 2 giá trị"));
	m_chon_chuong_trinh.AddString(_T("Tao mang một chiều"));
	m_chon_chuong_trinh.AddString(_T("Tạo mảng 2 chiều"));
	// 
	m_chon_chuong_trinh.SetCurSel(0);
	kieu_du_lieu.SetCurSel(0);
	

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
		path = _T("D:\\Code\\du an sinh tes\\sinhtest\\");
		tenthumuc.taoTM((path+ten_TM));

	for (int i = batdau; i < soluong+batdau; i++)
	{
	
		//sinh file output
		CString path_file_out = path + path_foder + "\\" + output;
		ofstream taooutput;
		taooutput.open(path_file_out);
		taooutput.close();
	}
	if (m_chon_chuong_trinh.GetCurSel() == 0) 
	{
		if (kieu_du_lieu.GetCurSel() == 0)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);

				int n= sinh_file_input().sinhsongaunhien_int(rand_batdau,rand_ketthuc);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				int n = sinh_file_input().sinhsongaunhien_int(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
		}
		else if (kieu_du_lieu.GetCurSel() == 1)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				float n = sinh_file_input().sinhsongaunhien_float(rand_batdau, rand_ketthuc);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++) 
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				float n = sinh_file_input().sinhsongaunhien_float(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
		}
		else if (kieu_du_lieu.GetCurSel() == 2)
		{
			for (int i = tes_bd_1; i <=tes_kt_1; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhkytugaunhien_char(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
		}
		else if (kieu_du_lieu.GetCurSel() == 3)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);			
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhchuoingaunhien(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
		}
		else if (kieu_du_lieu.GetCurSel() == 4)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{

				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhsongaunhien_boll(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput.close();
				Sleep(1000);
			}
		}

	}
	else if (m_chon_chuong_trinh.GetCurSel() == 1)
	{
		if (kieu_du_lieu.GetCurSel() == 0)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				int n = sinh_file_input().sinhsongaunhien_int(rand_batdau, rand_ketthuc);
				taoinput << n;
				taoinput << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios::app);
				int a= sinh_file_input().sinhsongaunhien_int(rand_batdau, rand_ketthuc);
				taoinput << a;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				int n = sinh_file_input().sinhsongaunhien_int(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios::app);
				int a = sinh_file_input().sinhsongaunhien_int(rand_bd_1, rand_kt_1);
				taoinput << a;
				taoinput.close();
				Sleep(1000);


			}
		}
		else if (kieu_du_lieu.GetCurSel() == 1)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				float n = sinh_file_input().sinhsongaunhien_float(rand_batdau, rand_ketthuc);
				taoinput << n;
				taoinput << endl;
				taoinput.close();
				taoinput.open(path_file_in,ios_base::app);
				float a = sinh_file_input().sinhsongaunhien_float(rand_batdau, rand_ketthuc);
				taoinput << a;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				float n = sinh_file_input().sinhsongaunhien_float(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios_base::app);
				float a = sinh_file_input().sinhsongaunhien_float(rand_bd_1, rand_kt_1);
				taoinput << a;
				taoinput.close();
				Sleep(1000);

			}
		}
		else if (kieu_du_lieu.GetCurSel() == 2)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
				taoinput << n;
				taoinput << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios_base::app);
				string a = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
				taoinput << a;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhkytugaunhien_char(rand_bd_1, rand_kt_1);
				taoinput << n;
				taoinput << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios_base::app);
				string a = sinh_file_input().sinhkytugaunhien_char(rand_bd_1, rand_kt_1);
				taoinput << a;
				taoinput.close();
				Sleep(1000);


			}
		}
		else if (kieu_du_lieu.GetCurSel() == 3)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);

				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
				taoinput << n<<endl;
				taoinput.close();
				taoinput.open(path_file_in,ios_base::app);
				string a = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
				taoinput << a ;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				//tao forder test
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhchuoingaunhien(rand_bd_1, rand_kt_1);
				taoinput << n << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios_base::app);
				string a = sinh_file_input().sinhchuoingaunhien(rand_bd_1, rand_kt_1);
				taoinput << a;
				taoinput.close();
				Sleep(1000);

				
			}
		}
		if (kieu_du_lieu.GetCurSel() == 4)
		{
			for (int i = tes_bd_1; i <= tes_kt_1; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
				taoinput << n<<endl;
				taoinput.close();
				taoinput.open(path_file_in,ios_base::app);
				string a = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
				taoinput << a << endl;
				taoinput.close();
				Sleep(1000);
			}
			for (int i = test_bd_2; i <= test_kt_2; i++)
			{
				//tao forder test
				path_add.Format(_T("%d"), i);
				path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
				tenthumuctest.taoTMTEST(path + path_foder);
				// sinh file iuput
				path_file_in = path + path_foder + "\\" + input;
				ofstream taoinput;
				taoinput.open(path_file_in);
				string n = sinh_file_input().sinhsongaunhien_boll(rand_bd_1, rand_kt_1);
				taoinput << n << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios_base::app);
				string a = sinh_file_input().sinhsongaunhien_boll(rand_bd_1, rand_kt_1);
				taoinput << a << endl;
				taoinput.close();
				Sleep(1000);


			}
		}

	}
	else if (m_chon_chuong_trinh.GetCurSel() == 2)
	{
		if (kieu_du_lieu.GetCurSel() == 0)
	{
		for (int i = tes_bd_1; i <= tes_kt_1; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);
			
			int nPhantu = 0;
			int* n_mangphantu = sinh_file_input().sinhmangso_int(rand_batdau, rand_ketthuc, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << n_mangphantu[i] << " ";
			}
			taoinput.close();	
			Sleep(1000);
		}
		for (int i = test_bd_2; i <= test_kt_2; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);

			int nPhantu = 0;
			int* n_mangphantu = sinh_file_input().sinhmangso_int(rand_bd_1, rand_kt_1, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << n_mangphantu[i] << " ";
			}
			taoinput.close();
			Sleep(1000);

		}
	}
		else if (kieu_du_lieu.GetCurSel() == 1)
	{
		for (int i = tes_bd_1; i <= tes_kt_1; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);

			int nPhantu = 0;
			float* n_mangphantu = sinh_file_input().sinhmangso_float(rand_batdau, rand_ketthuc, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << n_mangphantu[i] << " ";
			}
			taoinput.close();
			Sleep(1000);
		}
		for (int i = test_bd_2; i <= test_kt_2; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);

			int nPhantu = 0;
			float* n_mangphantu = sinh_file_input().sinhmangso_float(rand_bd_1, rand_kt_1, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << n_mangphantu[i] << " ";
			}
			taoinput.close();
			Sleep(1000);

		}
	}
		else if (kieu_du_lieu.GetCurSel() == 2)
	{
		for (int i = tes_bd_1; i <= tes_kt_1; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);
			string n = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
			taoinput << n;
			taoinput << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios_base::app);
			string a = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
			taoinput << a;
			taoinput.close();
			Sleep(1000);
		}
		for (int i = test_bd_2; i <= test_kt_2; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);
			string n = sinh_file_input().sinhkytugaunhien_char(rand_bd_1, rand_kt_1);
			taoinput << n;
			taoinput << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios_base::app);
			string a = sinh_file_input().sinhkytugaunhien_char(rand_bd_1, rand_kt_1);
			taoinput << a;
			taoinput.close();
			Sleep(1000);


		}
	}
		else if (kieu_du_lieu.GetCurSel() == 3)
	{
		for (int i = tes_bd_1; i <= tes_kt_1; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);

			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);
			string n = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
			taoinput << n << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios_base::app);
			string a = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
			taoinput << a;
			taoinput.close();
			Sleep(1000);
		}
		for (int i = test_bd_2; i <= test_kt_2; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			//tao forder test
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);
			string n = sinh_file_input().sinhchuoingaunhien(rand_bd_1, rand_kt_1);
			taoinput << n << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios_base::app);
			string a = sinh_file_input().sinhchuoingaunhien(rand_bd_1, rand_kt_1);
			taoinput << a;
			taoinput.close();
			Sleep(1000);


		}
	}
		else if (kieu_du_lieu.GetCurSel() == 4)
	{
		for (int i = tes_bd_1; i <= tes_kt_1; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);
			string n = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
			taoinput << n << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios_base::app);
			string a = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
			taoinput << a << endl;
			taoinput.close();
			Sleep(1000);
		}
		for (int i = test_bd_2; i <= test_kt_2; i++)
		{
			//tao forder test
			path_add.Format(_T("%d"), i);
			path_foder = ten_TM + "\\" + ten_TMTEST + path_add;
			tenthumuctest.taoTMTEST(path + path_foder);
			// sinh file iuput
			path_file_in = path + path_foder + "\\" + input;
			ofstream taoinput;
			taoinput.open(path_file_in);
			string n = sinh_file_input().sinhsongaunhien_boll(rand_bd_1, rand_kt_1);
			taoinput << n << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios_base::app);
			string a = sinh_file_input().sinhsongaunhien_boll(rand_bd_1, rand_kt_1);
			taoinput << a << endl;
			taoinput.close();
			Sleep(1000);


		}
	}

	}
	
}

