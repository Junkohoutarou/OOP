#include "PhanSo.h"
#include <iostream>
#include <cstring>
#include <stdio.h>


using namespace std;
int main() {

	PhanSo a;
	a.Nhap();
	a.Xuat();
	a.Thapphan();
	PhanSo c;
	PhanSo b;
	b.Nhap();
	c = a.Cong(b);
	cout << "Tong cua hai phan so la: ";
	c.xuat();
	c = a.Tru(b);
	cout << "Hieu cua hai phan so la: ";
	c.xuat();
	c = a.Nhan(b);
	cout << "Tich cua hai phan so la: ";
	c.xuat();
	c = a.Chia(b);
	cout << "Thuong cua hai phan so la: ";
	c.xuat();

	return 0;

}