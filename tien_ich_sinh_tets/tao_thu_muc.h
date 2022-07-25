#pragma once

#include<io.h>
#include<iostream>
#include<fstream>
using namespace std;

// tao_thu_muc dialog

class tao_thu_muc : public CDialogEx
{
	DECLARE_DYNAMIC(tao_thu_muc)

public:
	
	tao_thu_muc(CWnd* pParent = nullptr);   // standard constructor
	virtual ~tao_thu_muc();
	void taoTM(CString TM);
	void taoTMTEST(CString TM);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIEN_ICH_SINH_TETS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
