#pragma once
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <iomanip>

const int N = 100;

using namespace std;

class DaThuc {
private:
	double HeSo[N];
	int SoMu[N];
	int n;
public:
	DaThuc();
	void nhap();
	void xuat();
	void Tinhdathuc();
	DaThuc Congdathuc(DaThuc B);
	DaThuc Trudathuc(DaThuc B);
	~DaThuc();
};