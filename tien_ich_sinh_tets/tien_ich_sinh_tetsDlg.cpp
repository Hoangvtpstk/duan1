
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
	DDX_Control(pDX, IDC_QTXULY, m_quatrinhXL);
}

BEGIN_MESSAGE_MAP(CtienichsinhtetsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_TEN_TM, &CtienichsinhtetsDlg::OnEnChangeTenTm)
	
	ON_BN_CLICKED(IDC_BUTTON1, &CtienichsinhtetsDlg::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDC_BUTTON2, &CtienichsinhtetsDlg::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CtienichsinhtetsDlg message handlers

BOOL CtienichsinhtetsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*m_quatrinhXL.SetRange(0, 100);
	m_quatrinhXL.SetStep(1);

	SetTimer(1, 40, NULL);*/
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

	m_quatrinhXL.SetPos(0);
	
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

void CtienichsinhtetsDlg::OnEnChangeTenTm(){}

void CtienichsinhtetsDlg::taothumuc_test(int chonCT, int chonKDL,int testBD,int testKT,int rand_BD,int rand_KT,int &nint, float &nfloat, string &nstring)
{
	CString path;
	CString path_add;
	CString path_foder;
	tao_thu_muc   tenthumuc;
	tao_thu_muc   tenthumuctest;
	CString path_file_in;
	// tao thu muc cha
	UpdateData(TRUE);
	path = _T("sinhtest\\");
	tenthumuc.taoTM((path));
	tenthumuc.taoTM((path + ten_TM));
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
		
		// sinh 1 so
		if(chonCT==0 && chonKDL==0) {
			nint = sinh_file_input().sinhsongaunhien_int(rand_BD, rand_KT);
			taoinput << nint;
			taoinput.close();
			Sleep(1000);
		}
			
		else if (chonCT == 0 && chonKDL == 1) {
			nfloat = sinh_file_input().sinhsongaunhien_float(rand_BD, rand_KT);
			taoinput << roundf(nfloat*100)/100;
			taoinput.close();
			Sleep(1000);
		}
		else if (chonCT == 0 && chonKDL == 2) {
			nstring = sinh_file_input().sinhkytugaunhien_char(rand_BD, rand_KT);
			taoinput << nstring;
			taoinput.close();
			Sleep(1000);
		}
		else if (chonCT == 0 && chonKDL == 3)
		{
			nstring = sinh_file_input().sinhchuoingaunhien(rand_BD, rand_KT);
			taoinput << nstring;
			taoinput.close();
			Sleep(1000);
		}
		else if (chonCT == 0 && chonKDL == 4) {
			nstring = sinh_file_input().sinhsongaunhien_boll(rand_BD, rand_KT);
			taoinput << nstring;
			taoinput.close();
			Sleep(1000);
		}
		// sinh 2 so
		else if (chonCT == 1 && chonKDL == 0) {
			 nint = sinh_file_input().sinhsongaunhien_int(rand_batdau, rand_ketthuc);
			taoinput << nint;
			taoinput << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios::app);
			nint = sinh_file_input().sinhsongaunhien_int(rand_batdau, rand_ketthuc);
			taoinput << nint;
			taoinput.close();
			Sleep(1000);

		}
		else if (chonCT == 1 && chonKDL == 1) {
			nfloat = sinh_file_input().sinhsongaunhien_float(rand_batdau, rand_ketthuc);
			taoinput << roundf(nfloat * 100) / 100;
			taoinput << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios::app);
			nfloat = sinh_file_input().sinhsongaunhien_float(rand_batdau, rand_ketthuc);
			taoinput << roundf(nfloat * 100) / 100;
			taoinput.close();
			Sleep(1000);

		}
		else if (chonCT == 1 && chonKDL == 2) {
			nstring = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
			taoinput << nstring;
			taoinput << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios::app);
			nstring = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
			taoinput << nstring;
			taoinput.close();
			Sleep(1000);

		}
		else if (chonCT == 1 && chonKDL == 3) {
			nstring = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
			taoinput << nstring;
			taoinput << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios::app);
			nstring = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
			taoinput << nstring;
			taoinput.close();
			Sleep(1000);

		}
		else if (chonCT == 1 && chonKDL == 4) {
			nstring = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
			taoinput << nstring;
			taoinput << endl;
			taoinput.close();
			taoinput.open(path_file_in, ios::app);
			nstring = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
			taoinput << nstring;
			taoinput.close();
			Sleep(1000);

		}

		//sinh mang
		else if (chonCT == 2 && chonKDL == 0) {
			int nPhantu = 0;
			int a[100];
			 sinh_file_input().sinhmangso_int(a, rand_batdau, rand_ketthuc, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << a[i] << " ";
			}
			taoinput.close();	
			Sleep(1000);

		}
		else if (chonCT == 2 && chonKDL == 1) {
			int nPhantu = 0;
			float a[100];
			sinh_file_input().sinhmangso_float(a, rand_batdau, rand_ketthuc, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << roundf(a[i] * 100) / 100 << " ";
			}
			taoinput.close();
			Sleep(1000);

		}
		else if (chonCT == 2 && chonKDL == 2) {
			int nPhantu = 0;
			char a[100];
			sinh_file_input().sinhmangso_char(a, rand_batdau, rand_ketthuc, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << a[i] << " ";
			}
			taoinput.close();
			Sleep(1000);

		}
		else if (chonCT == 2 && chonKDL == 3) {
			string lay_mang[10000];
			int nPhantu = 0;
			sinh_file_input().sinhmangso_string(lay_mang, rand_batdau, rand_ketthuc, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << lay_mang[i] << endl;
			}
			taoinput.close();
			Sleep(1000);


		}
		else if (chonCT == 2 && chonKDL == 4) {
			string lay_mang[100];
			int nPhantu = 0;
			sinh_file_input().sinhmangso_bool(lay_mang, rand_batdau, rand_ketthuc, nPhantu);
			taoinput << nPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				taoinput << lay_mang[i] << endl;
			}
			taoinput.close();
			Sleep(1000);

		}
			else if (chonCT == 3 && chonKDL == 0) {
			int nPhantu = 0;
			int mPhantu = 0;
			int a[100][100];
			sinh_file_input().sinhmanghaichieu_int(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu);
			taoinput << nPhantu << " " << mPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				for (int j = 0; j < mPhantu; j++) {
					taoinput << a[i][j] << " ";
				}
				taoinput << endl;

		}
			Sleep(100);
			taoinput.close();


			}
			else if (chonCT == 3 && chonKDL == 1) {
			int nPhantu = 0;
			int mPhantu = 0;
			float a[50][50];
			sinh_file_input().sinhmanghaichieu_float(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu);
			taoinput << nPhantu << " " << mPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				for (int j = 0; j < mPhantu; j++) {
					taoinput << roundf(a[i][j] * 100) / 100 << " ";
				}
				taoinput << endl;

		}
			Sleep(100);
			taoinput.close();
			}
			else if (chonCT == 3 && chonKDL == 2) {
			int nPhantu = 0;
			int mPhantu = 0;
			char a[50][50];
			sinh_file_input().sinhmang2chieu_char(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu);
			taoinput << nPhantu << " " << mPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				for (int j = 0; j < mPhantu; j++) {
					taoinput << a[i][j] << " ";
				}
				taoinput << endl;

			}
			Sleep(100);
			taoinput.close();
			}
			else if (chonCT == 3 && chonKDL == 3) {
			int nPhantu = 0;
			int mPhantu = 0;
			char a[10][10];
			int soluongchuoi = 0;
			sinh_file_input().sinhmang2chieu_string(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu, soluongchuoi);
			taoinput << nPhantu << " " << mPhantu << " " << soluongchuoi << endl;
			for (int i = 0; i < nPhantu; i++) {
				for (int j = 0; j < mPhantu; j++) {
					taoinput << a[i][j] << " ";
				}
				taoinput << endl;

			}
			Sleep(100);
			taoinput.close();
			/*	sinh_file_input().sinhmang2chieu_string(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu, soluongchuoi);
				taoinput.open(path_file_in, ios::app);
				for (int i = 0; i < nPhantu; i++) {
					for (int j = 0; j < mPhantu; j++) {
						taoinput << a[i][j] << " ";
					}
					taoinput << endl;

				}
				Sleep(100);
				taoinput.close();*/
		}
			else if (chonCT == 3 && chonKDL == 4) {
			int nPhantu = 0;
			int mPhantu = 0;
			int a[100][100];
			sinh_file_input().sinhmanghaichieu_bool(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu);
			taoinput << nPhantu << " " << mPhantu << endl;
			for (int i = 0; i < nPhantu; i++) {
				for (int j = 0; j < mPhantu; j++) {
					taoinput << a[i][j] << " ";
				}
				taoinput << endl;

			}
			Sleep(100);
			taoinput.close();


			}
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

		// sinh 1 so
				if (chonCT == 0 && chonKDL == 0){
				nint = sinh_file_input().sinhsongaunhien_int(rand_BD, rand_KT);
				taoinput << nint;
				taoinput.close();
				Sleep(1000);
		}
			
		else if (chonCT == 0 && chonKDL == 1) {
				nfloat = sinh_file_input().sinhsongaunhien_float(rand_BD, rand_KT);
				taoinput << roundf(nfloat * 100) / 100;
				taoinput.close();
				Sleep(1000);
		}
		else if (chonCT == 0 && chonKDL == 2) {
				nstring = sinh_file_input().sinhkytugaunhien_char(rand_BD, rand_KT);
				taoinput << nstring;
				taoinput.close();
				Sleep(1000);
			}
			
		else if (chonCT == 0 && chonKDL == 3) {
				nstring = sinh_file_input().sinhchuoingaunhien(rand_BD, rand_KT);
				taoinput << nstring;
				taoinput.close();
				Sleep(1000);
			}
		else if (chonCT == 0 && chonKDL == 4) {
				nstring = sinh_file_input().sinhsongaunhien_boll(rand_BD, rand_KT);
				taoinput << nstring;
				taoinput.close();
				Sleep(1000);
			}

	// sinh 2 so
		else if (chonCT == 1 && chonKDL == 0) {
				nint = sinh_file_input().sinhsongaunhien_int(rand_batdau, rand_ketthuc);
				taoinput << nint;
				taoinput << endl;
				taoinput.close();
				taoinput.open(path_file_in, ios::app);
				nint = sinh_file_input().sinhsongaunhien_int(rand_batdau, rand_ketthuc);
				taoinput << nint;
				taoinput.close();
				Sleep(1000);

				}
		else if (chonCT == 1 && chonKDL == 1) {
					nfloat = sinh_file_input().sinhsongaunhien_float(rand_batdau, rand_ketthuc);
					taoinput << roundf(nfloat*100)/100;
					taoinput << endl;
					taoinput.close();
					taoinput.open(path_file_in, ios::app);
					nfloat = sinh_file_input().sinhsongaunhien_float(rand_batdau, rand_ketthuc);
					taoinput << roundf(nfloat * 100) / 100;
					taoinput.close();
					Sleep(1000);

				}
		else if (chonCT == 1 && chonKDL == 2) {
					nstring = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
					taoinput << nstring;
					taoinput << endl;
					taoinput.close();
					taoinput.open(path_file_in, ios::app);
					nstring = sinh_file_input().sinhkytugaunhien_char(rand_batdau, rand_ketthuc);
					taoinput << nstring;
					taoinput.close();
					Sleep(1000);

				}
		else if (chonCT == 1 && chonKDL == 3) {
					nstring = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
					taoinput << nstring;
					taoinput << endl;
					taoinput.close();
					taoinput.open(path_file_in, ios::app);
					nstring = sinh_file_input().sinhchuoingaunhien(rand_batdau, rand_ketthuc);
					taoinput << nstring;
					taoinput.close();
					Sleep(1000);

				}
		else if (chonCT == 1 && chonKDL == 4) {
					nstring = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
					taoinput << nstring;
					taoinput << endl;
					taoinput.close();
					taoinput.open(path_file_in, ios::app);
					nstring = sinh_file_input().sinhsongaunhien_boll(rand_batdau, rand_ketthuc);
					taoinput << nstring;
					taoinput.close();
					Sleep(1000);

				}
				//sinh mang
		else if (chonCT == 2 && chonKDL == 0) {
					int nPhantu = 0;
					int a[100];
					sinh_file_input().sinhmangso_int(a, rand_batdau, rand_ketthuc, nPhantu);
					taoinput << nPhantu << endl;
					for (int i = 0; i < nPhantu; i++) {
						taoinput << a[i] << " ";
					}
					taoinput.close();
					Sleep(1000);

				}
		else if (chonCT == 2 && chonKDL == 1) {
					int nPhantu = 0;
					float a[100];
					sinh_file_input().sinhmangso_float(a, rand_batdau, rand_ketthuc, nPhantu);
					taoinput << nPhantu << endl;
					for (int i = 0; i < nPhantu; i++) {
						taoinput << roundf(a[i] * 100) / 100 << " ";
					}
					taoinput.close();
					Sleep(1000);

				}
		else if (chonCT == 2 && chonKDL == 2) {
					int nPhantu = 0;
					char a[100];
					sinh_file_input().sinhmangso_char(a, rand_batdau, rand_ketthuc, nPhantu);
					taoinput << nPhantu << endl;
					for (int i = 0; i < nPhantu; i++) {
						taoinput << a[i] << " ";
					}
					taoinput.close();
					Sleep(1000);

		}
		else if (chonCT == 2 && chonKDL == 3) {
					string lay_mang[10000];
					int nPhantu = 0;
					 sinh_file_input().sinhmangso_string(lay_mang, rand_batdau, rand_ketthuc, nPhantu);
					taoinput << nPhantu << endl;
					for (int i = 0; i < nPhantu; i++) {		
							taoinput << lay_mang[i]<<endl;				
					}
					taoinput.close();
					Sleep(1000);

		}
					else if (chonCT == 2 && chonKDL == 4) {
					string lay_mang[100];
					int nPhantu = 0;
					sinh_file_input().sinhmangso_bool(lay_mang, rand_batdau, rand_ketthuc, nPhantu);
					taoinput << nPhantu << endl;
					for (int i = 0; i < nPhantu; i++) {
						taoinput << lay_mang[i] << endl;
					}
					taoinput.close();
					Sleep(1000);

		}
		// sinh mang 2 chieu
		else if (chonCT == 3 && chonKDL == 0) {
			int nPhantu = 0;
				int mPhantu = 0;
				int a[100][100];
				 sinh_file_input().sinhmanghaichieu_int( a,rand_batdau, rand_ketthuc, nPhantu, mPhantu);
				taoinput << nPhantu << " "<< mPhantu<<endl;
				for (int i = 0; i < nPhantu; i++) {
					for (int j = 0; j < mPhantu; j++) {
						taoinput << a[i][j] << " ";					
					}
					taoinput << endl;
				
				}
				Sleep(100);
				taoinput.close();


		}
		else if (chonCT == 3 && chonKDL == 1) {
					int nPhantu = 0;
					int mPhantu = 0;
					float a[50][50];
					sinh_file_input().sinhmanghaichieu_float(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu);
					taoinput << nPhantu << " " << mPhantu << endl;
					for (int i = 0; i < nPhantu; i++) {
						for (int j = 0; j < mPhantu; j++) {
							taoinput << roundf(a[i][j] * 100) / 100 << " ";
						}
						taoinput << endl;

					}
					Sleep(100);
					taoinput.close();
				}
		else if (chonCT == 3 && chonKDL == 2) {
					int nPhantu = 0;
					int mPhantu = 0;
					char a[50][50];
					sinh_file_input().sinhmang2chieu_char(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu);
					taoinput << nPhantu << " " << mPhantu << endl;
					for (int i = 0; i < nPhantu; i++) {
						for (int j = 0; j < mPhantu; j++) {
							taoinput << a[i][j]  << " ";
						}
						taoinput << endl;

					}
					Sleep(100);
					taoinput.close();
				}
		else if (chonCT == 3 && chonKDL == 3) {
		int nPhantu = 0;
		int mPhantu = 0;
		char a[10][10];
		int soluongchuoi=0;
		sinh_file_input().sinhmang2chieu_string(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu,soluongchuoi);
		taoinput << nPhantu << " " << mPhantu <<" "<<soluongchuoi<< endl;
		for (int i = 0; i < nPhantu; i++) {
			for (int j = 0; j < mPhantu; j++) {
				taoinput << a[i][j] << " ";
			}
			taoinput << endl;

		}
		Sleep(100);
		taoinput.close();
		/*	sinh_file_input().sinhmang2chieu_string(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu, soluongchuoi);
			taoinput.open(path_file_in, ios::app);
			for (int i = 0; i < nPhantu; i++) {
				for (int j = 0; j < mPhantu; j++) {
					taoinput << a[i][j] << " ";
				}
				taoinput << endl;

			}
			Sleep(100);
			taoinput.close();*/
		}
		else if (chonCT == 3 && chonKDL == 4) {
		int nPhantu = 0;
		int mPhantu = 0;
		int a[100][100];
		sinh_file_input().sinhmanghaichieu_bool(a, rand_batdau, rand_ketthuc, nPhantu, mPhantu);
		taoinput << nPhantu << " " << mPhantu << endl;
		for (int i = 0; i < nPhantu; i++) {
			for (int j = 0; j < mPhantu; j++) {
				taoinput << a[i][j] << " ";
			}
			taoinput << endl;

		}
		Sleep(100);
		taoinput.close();


			}
	}
}



void CtienichsinhtetsDlg::OnBnClickedButton1()
{
	m_quatrinhXL.SetPos(0);
	nProgressCheck = 0;
	for (size_t i = 0; i <=100; i++)
	{
		m_quatrinhXL.SetPos(i);
		Sleep(10);
	}
	m_quatrinhXL.SetPos(100);
	//SetTimer(0, 100, NULL);

	CString path;
	CString path_add;
	CString path_foder;
	tao_thu_muc   tenthumuc;
	tao_thu_muc   tenthumuctest;
	CString path_file_in;
	int nint; float nfloat;
	string nstring;
	//for (int i = batdau; i < soluong+batdau; i++)
	//{
	//
	//	//sinh file output
	//	CString path_file_out = path + path_foder + "\\" + output;
	//	ofstream taooutput;
	//	taooutput.open(path_file_out);
	//	taooutput.close();
	//}
	
		if (m_chon_chuong_trinh.GetCurSel() == 0) 
	{
		if (kieu_du_lieu.GetCurSel() == 0)
		{
			
			
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc,nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);
			
		}
		else if (kieu_du_lieu.GetCurSel() == 1)
		{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);
			
			
		}
		else if (kieu_du_lieu.GetCurSel() == 2)
		{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

			
		}
		else if (kieu_du_lieu.GetCurSel() == 3)
		{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		}
		else if (kieu_du_lieu.GetCurSel() == 4)
		{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		}

	}
	else if (m_chon_chuong_trinh.GetCurSel() == 1)
	{
		if (kieu_du_lieu.GetCurSel() == 0)
		{

			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

			
		}
		else if (kieu_du_lieu.GetCurSel() == 1)
		{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		}
		else if (kieu_du_lieu.GetCurSel() == 2)
		{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		}
		else if (kieu_du_lieu.GetCurSel() == 3)
		{
			
				taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
				taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);
	
		}
		if (kieu_du_lieu.GetCurSel() == 4)
		{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		}

	}
	else if (m_chon_chuong_trinh.GetCurSel() == 2)
	{
		if (kieu_du_lieu.GetCurSel() == 0)
	{

			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		
	}
		else if (kieu_du_lieu.GetCurSel() == 1)

	{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

	}
		else if (kieu_du_lieu.GetCurSel() == 2)
	{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		
	}
		else if (kieu_du_lieu.GetCurSel() == 3)
	{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		}
		else if (kieu_du_lieu.GetCurSel() == 4)
	{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);
	
	}

	}


	else if (m_chon_chuong_trinh.GetCurSel() == 3)
	{
		if (kieu_du_lieu.GetCurSel() == 0)
	{

		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

	}
		else if (kieu_du_lieu.GetCurSel() == 1)
	{
		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		
	}
	else if (kieu_du_lieu.GetCurSel() == 2)
	{
		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);

		
	}
	else if (kieu_du_lieu.GetCurSel() == 3)
	{
		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
		taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);
		
	}
	else if (kieu_du_lieu.GetCurSel() == 4)
	{
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), tes_bd_1, tes_kt_1, rand_batdau, rand_ketthuc, nint, nfloat, nstring);
			taothumuc_test(m_chon_chuong_trinh.GetCurSel(), kieu_du_lieu.GetCurSel(), test_bd_2, test_kt_2, rand_bd_1, rand_kt_1, nint, nfloat, nstring);
			
	}

	}
}




void CtienichsinhtetsDlg::OnBnClickedButton2()
{
	sinh_out fileout;
	fileout.DoModal();
}


void CtienichsinhtetsDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 0)
	{
		nProgressCheck++;
		m_quatrinhXL.SetPos(nProgressCheck);

		if (nProgressCheck == 100)
		{
			KillTimer(0);
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}
