#include <iostream>
#include "mangmotchieu.h"
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>


using namespace std;

bool soNguyenTo(int soA)
{
	if (soA < 2)
		return false;

	for (int i = 2; i <= sqrt((float)soA); i++)
	{
		if (soA % i == 0)
		{
			return false;
		}
	}
	return true;
}

mangmotchieu::mangmotchieu()
{
	n = 0;
}

mangmotchieu::mangmotchieu(int n, int a[N])
{
	this->n = n;
	for (int i = 0; i < n; i++)
	{
		this->a[i] = a[i];
	}
}

void mangmotchieu::nhap()
{
	cout << "Vui long nhap gia tri cua mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Vui long nhap phan tu thu " << i + 1 << " :";
		cin >> a[i];
		cout << endl;
	}
}

void mangmotchieu::xuat()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Vui long nhap phan tu thu " << i + 1 << " :";
		cout << a[i];
		cout << endl;
	}
}

void mangmotchieu::x_Count()
{
	int x;
	cout << "Vui long nhap gia tri cua x: ";
	cin >> x;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) { dem++; }
	}
	cout << endl;
	cout << "So gia tri giong voi X la: ";
	cout << dem;
}

void mangmotchieu::check_increase()
{
	bool check = true;
	a[n] = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i + 1])
		{
			check = false;
			break;
		}
		else continue;
	}
	if (check == true) cout << "Day la day so nguyen tang dan ";
	else cout << "Day khong la day so nguyen tang dan ";
}

void mangmotchieu::odd_min()
{
	int tam;
	tam = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 1)
		{
			tam = min(tam, a[i]);
		}
	}
	cout << "Gia tri le nho nhat trong day so nguyen la: ";
	cout << tam;
}

void mangmotchieu::max_prime()
{
	int tam;
	tam = 0;
	for (int i = 0; i < n; i++)
	{
		if (soNguyenTo(a[i]))
		{
			tam = max(tam, a[i]);
		}
	}
	cout << "So nguyen to lon nhat trong mang la: ";
	cout << tam;
}

mangmotchieu::~mangmotchieu() {};