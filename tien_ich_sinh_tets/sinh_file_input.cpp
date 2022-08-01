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

void sinh_file_input::sinhmangso_int(int a[100],int bat_dau, int ket_thuc, int &n_phatu) {
	srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
		for (  int i = bat_dau; i <= n; i++) {
		a[i] = rand() % (ket_thuc - bat_dau + 1) + bat_dau;
		cout << "  ";
		}
	n_phatu = n;
	
}
void sinh_file_input::sinhmangso_float(float a[100],int bat_dau, int ket_thuc, int& n_phatu)
{
	//srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	
		for (int i = bat_dau; i <= n; i++) {
		a[i] = (float)bat_dau + (float)(ket_thuc - bat_dau) * (float)rand() / (float)RAND_MAX;
		 		cout << "  ";
	}
	n_phatu = n;
	

}
void sinh_file_input::sinhmangso_char(char a[255],int bat_dau, int ket_thuc, int& n_phatu)
{
	srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789");

	for (int i = bat_dau; i <= n; i++) {
		a[i] = xaus[rand() % xaus.size()];
		cout << "  ";
	}
	n_phatu = n;
	
}
void sinh_file_input::sinhmangso_string(string* lay_mang,int bat_dau, int ket_thuc, int& n_phatu)
{
	srand(time(NULL));
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789");
	string s;
		int n = rand() % ket_thuc - bat_dau;
	
	for (size_t k = bat_dau; k < n; k++)
	{
		int m = rand() % ket_thuc - bat_dau;
		for (int i = bat_dau; i <=m; i++) {
			s = xaus[rand() % xaus.size()];
			lay_mang[k] += s;
			cout << endl;
		}
		
	}
	n_phatu = n;

}

void sinh_file_input::sinhmangso_bool(string* lay_mang, int bat_dau, int ket_thuc, int& n_phatu)
{
	srand(time(NULL));
	
	int n = rand() % ket_thuc - bat_dau;
	int a;
	string str;
	
	for (size_t k = bat_dau; k < n; k++)
	{
		int m = rand() % ket_thuc - bat_dau;
		for (int i = bat_dau; i <= m; i++) {
			a = (rand() % 2);
			str = to_string(a);
			lay_mang[k] += str;
			cout << endl;
			
		}

	}
	n_phatu = n;
	


}

void sinh_file_input::sinhmanghaichieu_int(int a[100][100],int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu) {
	//srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	int m = rand() % ket_thuc - bat_dau;
	
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % (ket_thuc - bat_dau + 1) + bat_dau;
		}
		
	}
	n_phatu = n;
	m_phantu = m;

	
}

void sinh_file_input::sinhmanghaichieu_float(float a[50][50], int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu) {
	//srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	int m = rand() % ket_thuc - bat_dau;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			a[i][j] =(float)bat_dau + (float)(ket_thuc - bat_dau) * (float)rand() / (float)RAND_MAX; ;
		}

	}
	n_phatu = n;
	m_phantu = m;


}
void sinh_file_input::sinhmang2chieu_char(char a[50][50], int bat_dau, int ket_thuc,  int& n_phatu, int& m_phantu)
{
	//srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	int m = rand() % ket_thuc - bat_dau;
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = xaus[rand() % xaus.size()];
		}

	}
	n_phatu = n;
	m_phantu = m;

	
}
void sinh_file_input::sinhmang2chieu_string(char a[10][10], int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu,int& soluongchuoi)
{
	//srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	int m = rand() % ket_thuc - bat_dau;
	int k = rand() % 10;
	string xaus = ("QWERTYUIOPLKJHGFDSAZXCVBNMabcdefghijklmnopqrstuvwxyz0123456789");
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = xaus[rand() % xaus.size()];
			}

		}
	
	n_phatu = n;
	m_phantu = m;
	soluongchuoi = k;

}
void sinh_file_input::sinhmanghaichieu_bool (int a[100][100], int bat_dau, int ket_thuc, int& n_phatu, int& m_phantu) {
	//srand(time(NULL));
	int n = rand() % ket_thuc - bat_dau;
	int m = rand() % ket_thuc - bat_dau;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 2;
		}

	}
	n_phatu = n;
	m_phantu = m;


}