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
	//DDX_Control(pDX, IDC_LISTINPUT, m_listinput);


}


BEGIN_MESSAGE_MAP(tao_thu_muc, CDialogEx)
	//ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &tao_thu_muc::OnTvnSelchangedTree1)
	//ON_CBN_SELCHANGE(IDC_COMBO1, &tao_thu_muc::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// tao_thu_muc message handlers
void tao_thu_muc::taoTM(CString ten_TM) {
	
	_tmkdir(ten_TM);
}
void tao_thu_muc::taoTMTEST(CString ten_TMTEST) {

	_tmkdir(ten_TMTEST);
	
}


