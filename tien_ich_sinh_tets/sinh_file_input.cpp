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
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+=-\][{}';""/.,<>?:|");
	string s;
	s = xaus[rand() % xaus.size()];
	
	return s;
}
string sinh_file_input::sinhchuoingaunhien(int bat_dau, int ket_thuc) {
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+=-\][{}';""/.,<>?:|");
	string s;
	string str;
	int n = rand() % ket_thuc - bat_dau;
		for (int i = bat_dau; i <=n; i++) {
		s= xaus[rand() % xaus.size()];
		str += s;
	}
		return str;
}
string sinh_file_input::sinhsongaunhien_boll(int bat_dau, int ket_thuc) {
	//srand(time(NULL));
	
	int n = rand() % ket_thuc - bat_dau;
	int a;
	string str,chuoi;
	for (int i = bat_dau; i <= n; i++) {
		a=  (rand() % 2) ;
		str = to_string(a);
		chuoi += str;
		
	}
	//a = atoi(chuoi.c_str());
	return chuoi;
	 
	
}
int* sinh_file_input::sinhmangso_int(int bat_dau, int ket_thuc, int &n_phatu) {
	srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	int i;
	int a[10000];
	for (   i = bat_dau; i <= n; i++) {
		a[i] = rand() % (ket_thuc - bat_dau + 1) + bat_dau;
		cout << "  ";
		}
	n_phatu = n;
	return a;
	
}
float* sinh_file_input::sinhmangso_float(int bat_dau, int ket_thuc, int& n_phatu)
{
	//srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	int i;
	float a[10000];
	for (i = bat_dau; i <= n; i++) {
		a[i] = (float)bat_dau + (float)(ket_thuc - bat_dau) * (float)rand() / (float)RAND_MAX;
		 		cout << "  ";
	}
	n_phatu = n;
	return a;

}
char* sinh_file_input::sinhmangso_char(int bat_dau, int ket_thuc, int& n_phatu)
{
	srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+=-\][{}';""/.,<>?:|");
	
	char a[10000];
	
	for (int i = bat_dau; i <= n; i++) {
		a[i] = xaus[rand() % xaus.size()];
		cout << "  ";
	}
	n_phatu = n;
	return a;

}
void sinh_file_input::sinhmangso_string(string *output_string, int bat_dau, int ket_thuc, int& n_phatu)
{
	srand(time(NULL));
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+=-\][{}';""/.,<>?:|");
	string s;
	int n = rand() % ket_thuc - bat_dau;
	
	for (size_t k = bat_dau; k < n; k++)
	{
		int m = rand() % ket_thuc - bat_dau;
		for (int i = bat_dau; i <=m; i++) {
			s = xaus[rand() % xaus.size()];
			output_string[k] += s;
			cout << endl;
		}
		
	}
	n_phatu = n;	

}