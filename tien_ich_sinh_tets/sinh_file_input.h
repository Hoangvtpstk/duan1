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
	int* sinhmangso_int(int bat_dau, int ket_thuc, int& n_phatu);
	float* sinhmangso_float(int bat_dau, int ket_thuc, int& n_phatu);
};