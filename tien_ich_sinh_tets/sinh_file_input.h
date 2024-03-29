#pragma once
#include<string>
#include<io.h>
#include"tao_thu_muc.h"
#include <windows.h>
#include<fstream>
#include<time.h>
#include"sinh_file_input.h"
class sinh_file_input
{
public:
	int sinhsongaunhien_int(int bat_dau, int ket_thuc);
	float sinhsongaunhien_float(int bat_dau, int ket_thuc);\
	string sinhkytugaunhien_char(int bat_dau, int ket_thuc);
	string sinhchuoingaunhien(int bat_dau, int ket_thuc);
	string sinhsongaunhien_boll(int bat_dau, int ket_thuc);
	void sinhmangso_int(int a[100],int bat_dau, int ket_thuc, int& n_phatu);
	void sinhmangso_float(float a[1000], int bat_dau, int ket_thuc, int& n_phatu);
	void sinhmangso_char(char a[255],int bat_dau, int ket_thuc, int& n_phatu);
	void sinhmangso_string(string* lay_mang,int bat_dau, int ket_thuc, int& n_phatu);
	void sinhmangso_bool(string* lay_mang, int bat_dau, int ket_thuc, int& n_phatu);
	void sinhmanghaichieu_int(int a[100][100],int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu);
	void sinhmanghaichieu_float(float a[50][50], int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu);
	void sinhmang2chieu_char(char a[50][50], int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu);
	void sinhmang2chieu_string(char a[10][10], int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu,int& soluongchuoi);
	void sinhmanghaichieu_bool(int a[100][100], int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu);
};

