#pragma once
#include<iostream>
using namespace std;
class DSPhanso
{
private:
	int tuso;
	int mauso;
public:
	void Nhap1PS();
	void Xuat1PS();
	void xuat(DSPhanso a[], int n);
	void nhap(DSPhanso a[], int n);
	void rutgon();
	DSPhanso cong(DSPhanso a[], int n);
	DSPhanso phansomax(DSPhanso a[], int n);
	DSPhanso phansomin(DSPhanso a[], int n);
	void tangdan(DSPhanso a[], int n);
	void giamdan(DSPhanso a[], int n);
	~DSPhanso();
};
