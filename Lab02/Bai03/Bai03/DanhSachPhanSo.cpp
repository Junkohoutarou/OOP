#include"DanhSachPhanSo.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

int ucln(int a, int b)
{
	if (a == 0 || b == 0)return a + b;
	while (a != b)
	{
		if (a > b)a = a - b;
		else b = b - a;
	}
	return a;
}
void DSPhanso::rutgon()
{
	if (mauso == 0)return;
	int a = tuso < 0 ? -tuso : tuso;
	int b = mauso < 0 ? -mauso : mauso;
	if (tuso * mauso >= 0)
	{
		tuso = a;
		mauso = b;
	}
	else
	{
		tuso = -a;
		mauso = b;
	}
	int uoc = ucln(a, b);
	tuso /= uoc;
	mauso /= uoc;
}
void DSPhanso::Nhap1PS()
{
	cout << "Nhap tu so: ";
	cin >> tuso;
	do
	{
		cout << "Nhap mauso: ";
		cin >> mauso;
	} while (mauso == 0);
	rutgon();
}
void DSPhanso::Xuat1PS()
{
	rutgon();
	if (mauso < 0)
	{
		tuso = -tuso;
		mauso = -mauso;
	}
	if (mauso == 1)cout << tuso;
	else cout << tuso << "/" << mauso;
}
void DSPhanso::nhap(DSPhanso a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan so thu: " << i + 1 << endl;
		a[i].Nhap1PS();
	}
}
void DSPhanso::xuat(DSPhanso a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].Xuat1PS();
		cout << "\t";
	}
}
DSPhanso DSPhanso::cong(DSPhanso a[], int n)
{
	DSPhanso kq;
	kq.tuso = a[0].tuso;
	kq.mauso = a[0].mauso;
	for (int i = 1; i < n; i++)
	{
		kq.tuso = a[i].tuso * kq.mauso + a[i].mauso * kq.tuso;
		kq.mauso *= a[i].mauso;
	}
	return kq;
}
DSPhanso DSPhanso::phansomax(DSPhanso a[], int n)
{
	DSPhanso max;
	max.tuso = a[0].tuso;
	max.mauso = a[0].mauso;
	for (int i = 1; i < n; i++)
	{
		double tam = max.tuso * 1.0 / max.mauso;
		double tam2 = a[i].tuso * 1.0 / a[i].mauso;
		if (tam < tam2)
		{
			max.tuso = a[i].tuso;
			max.mauso = a[i].mauso;
		}
	}
	return max;
}
DSPhanso DSPhanso::phansomin(DSPhanso a[], int n)
{
	DSPhanso min;
	min.tuso = a[0].tuso;
	min.mauso = a[0].mauso;
	for (int i = 1; i < n; i++)
	{
		double tam = min.tuso * 1.0 / min.mauso;
		double tam2 = a[i].tuso * 1.0 / a[i].mauso;
		if (tam > tam2)
		{
			min.tuso = a[i].tuso;
			min.mauso = a[i].mauso;
		}
	}
	return min;
}
void DSPhanso::giamdan(DSPhanso a[], int n)
{
	DSPhanso tg;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double tam = a[i].tuso * 1.0 / a[i].mauso;
			double tam2 = a[j].tuso * 1.0 / a[j].mauso;
			if (tam < tam2)
			{
				tg.tuso = a[i].tuso;
				tg.mauso = a[i].mauso;
				a[i].tuso = a[j].tuso;
				a[i].mauso = a[j].mauso;
				a[j].tuso = tg.tuso;
				a[j].mauso = tg.mauso;
			}


		}
	}
}
void DSPhanso::tangdan(DSPhanso a[], int n)
{
	DSPhanso tg;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double tam = a[i].tuso * 1.0 / a[i].mauso;
			double tam2 = a[j].tuso * 1.0 / a[j].mauso;
			if (tam > tam2)
			{
				tg.tuso = a[i].tuso;
				tg.mauso = a[i].mauso;
				a[i].tuso = a[j].tuso;
				a[i].mauso = a[j].mauso;
				a[j].tuso = tg.tuso;
				a[j].mauso = tg.mauso;
			}


		}
	}
}

DSPhanso::~DSPhanso() {};
