
// tien_ich_sinh_tetsDlg.h : header file
//

#pragma once
#include"tao_thu_muc.h"
#include"sinh_file_input.h"
#include"sinh_file_output.h"
#include<fstream>

// CtienichsinhtetsDlg dialog
class CtienichsinhtetsDlg : public CDialogEx
{
// Construction
public:
	CtienichsinhtetsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIEN_ICH_SINH_TETS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString ten_TM;
	CString ten_TMTEST =_T("Test");
	
	afx_msg void OnEnChangeTenTm();

	afx_msg void OnBnClickedButton1();
	int soluong;
	int batdau;
	int ketthuc;
	int rand_batdau;
	int rand_ketthuc;


	int tes_bd_1;
	int tes_kt_1;
	CComboBox m_chon_chuong_trinh;
	CComboBox kieu_du_lieu;
	
	CString input;
	CString output;
	
	
};
