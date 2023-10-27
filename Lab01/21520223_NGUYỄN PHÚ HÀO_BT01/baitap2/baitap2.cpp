#include "sophuc.h"
#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
	sophuc a, b;
	a.nhap();
	a.xuat();
	b.nhap();

	sophuc c;
	c = a.tong(b);
	cout << "Tong cua hai so phuc la: ";
	c.Xuat();

	c = a.hieu(b);
	cout << "Hieu cua hai so phuc la: ";
	c.Xuat();

	c = a.tich(b);
	cout << "Tich cua hai so phuc la: ";
	c.Xuat();

	c = a.thuong(b);
	cout << "Thuong cua hai so phuc la: ";
	c.Xuat();
	return 0;
}

