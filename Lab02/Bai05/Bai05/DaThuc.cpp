#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include "DaThuc.h"

using namespace std;

DaThuc::DaThuc()
{
}

void DaThuc::nhap()
{
	cout << "Vui long nhap gia tri cua n: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Vui long nhap he so thu " << i + 1 << " :";
		cin >> HeSo[i];
		cout << "Vui long nhap he so thu " << i + 1 << " :";
		cin >> SoMu[i];
	}
}

void DaThuc::xuat()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (HeSo[i] != 0) {
			if (HeSo[i] > 0 && dem > 0)
				cout << "+";
			else if (HeSo[i] < 0)
				cout << "-";
			if (abs(HeSo[i]) != 1)
				cout << abs(HeSo[i]);
			else if (abs(HeSo[i]) == 1 && SoMu[i] == 0)
				cout << 1;
			else if (abs(HeSo[i]) != 1 && SoMu[i] == 0)
				cout << HeSo[i];
			if (SoMu[i] == 1)
				cout << "x";
			else if (SoMu[i] != 1 && SoMu[i] != 0)
				cout << "x^" << SoMu[i];
			dem++;
		}

	}
	if (dem == 0)
		cout << 0;
}

void DaThuc::Tinhdathuc()
{
	double s = 0;
	double x;
	cout << "Vui long nhap gia tri cua X: ";
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		s = s + HeSo[i] * pow(x, SoMu[i]);
	}
	cout << "Gia tri da thuc tai vi tri cua X la: ";
	cout << s;
}

DaThuc DaThuc::Congdathuc(DaThuc B)
{
	DaThuc c;
	int u = 0, i = 0, j = 0;
	int k = B.n;
	while (i < n && j < k)
	{
		if (SoMu[i] <= B.SoMu[j])
		{
			c.HeSo[u] = B.HeSo[j];
			c.SoMu[u++] = B.SoMu[j++];
		}
		else
		{
			c.HeSo[u] = HeSo[i];
			c.SoMu[u++] = SoMu[i++];
		}
	}
	while (i < n)
	{
		c.HeSo[u] = HeSo[i];
		c.SoMu[u++] = SoMu[i++];
	}
	while (j < k)
	{
		c.HeSo[u] = B.HeSo[j];
		c.SoMu[u++] = B.SoMu[j++];
	}
	c.n = u;
	for (int i = 0; i < c.n - 1; i++)
	{
		if (c.SoMu[i] == c.SoMu[i + 1])
		{
			c.HeSo[i] += c.HeSo[i + 1];

			for (int j = i + 1; j < c.n - 1; j++)
			{
				c.HeSo[j] = c.HeSo[j + 1];
				c.SoMu[j] = c.SoMu[j + 1];
			}
			c.n--;
		}
	}
	return c;
}

DaThuc DaThuc::Trudathuc(DaThuc B)
{
	DaThuc c;
	int u = 0, i = 0, j = 0;
	int k = B.n;
	while (i < n && j < k)
	{
		if (SoMu[i] <= B.SoMu[j])
		{
			c.HeSo[u] = B.HeSo[j];
			c.SoMu[u++] = B.SoMu[j++];
		}
		else
		{
			c.HeSo[u] = HeSo[i];
			c.SoMu[u++] = SoMu[i++];
		}
	}
	while (i < n)
	{
		c.HeSo[u] = HeSo[i];
		c.SoMu[u++] = SoMu[i++];
	}
	while (j < k)
	{
		c.HeSo[u] = B.HeSo[j];
		c.SoMu[u++] = B.SoMu[j++];
	}
	c.n = u;
	for (int i = 0; i < c.n - 1; i++)
	{
		if (c.SoMu[i] == c.SoMu[i + 1])
		{
			c.HeSo[i] = c.HeSo[i + 1] - c.HeSo[i];

			for (int j = i + 1; j < c.n - 1; j++)
			{
				c.HeSo[j] = c.HeSo[j + 1];
				c.SoMu[j] = c.SoMu[j + 1];
			}
			c.n--;
		}
	}
	return c;
}

DaThuc::~DaThuc() {};