#include "pch.h"
#include "sinh_file_input.h"
#include<time.h>

int sinh_file_input::sinhsongaunhien_int(int bat_dau, int ket_thuc) {
	//srand(time(NULL));
	float fRand = rand();
	float fRand_0_1 = fRand / RAND_MAX;
	int n = fRand_0_1 * (ket_thuc - bat_dau + 1) + bat_dau;
		return n;
}