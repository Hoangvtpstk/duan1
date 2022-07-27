#include "pch.h"
#include "sinh_file_input.h"
#include<time.h>
#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>


int sinh_file_input::sinhsongaunhien_int(int bat_dau, int ket_thuc) {
	//srand(time(NULL));
	
	int n = bat_dau+rand()%(ket_thuc - bat_dau + 1) ;
		return n;
}
float sinh_file_input::sinhsongaunhien_float(int bat_dau, int ket_thuc) {
	//srand(time(NULL));

	float n = (float)bat_dau + (float)(ket_thuc - bat_dau) * (float)rand() / (float)RAND_MAX;
	return n;
}
string sinh_file_input::sinhkytugaunhien_char(int bat_dau, int ket_thuc) {
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789");
	string s;
	s = xaus[rand() % xaus.size()];
	
	return s;
}
string sinh_file_input::sinhchuoingaunhien(int bat_dau, int ket_thuc) {
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789");
	string s;
	string str;
	int n = rand() % ket_thuc - bat_dau;
		for (int i = bat_dau; i <=n; i++) {
		s= xaus[rand() % xaus.size()];
		str += s;
	}
		return str;
}