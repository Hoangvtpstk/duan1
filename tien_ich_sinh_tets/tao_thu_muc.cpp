// tao_thu_muc.cpp : implementation file
//

#include "pch.h"
#include "tien_ich_sinh_tets.h"
#include "tao_thu_muc.h"
#include "afxdialogex.h"
#include <windows.h>


// tao_thu_muc dialog

IMPLEMENT_DYNAMIC(tao_thu_muc, CDialogEx)

tao_thu_muc::tao_thu_muc(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIEN_ICH_SINH_TETS_DIALOG, pParent)
{

}

tao_thu_muc::~tao_thu_muc()
{
}

void tao_thu_muc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(tao_thu_muc, CDialogEx)
END_MESSAGE_MAP()


// tao_thu_muc message handlers
void tao_thu_muc::taoTM(CString ten_TM) {
	
	_tmkdir(ten_TM);
}
void tao_thu_muc::taoTMTEST(CString ten_TMTEST) {

	_tmkdir(ten_TMTEST);
	
}