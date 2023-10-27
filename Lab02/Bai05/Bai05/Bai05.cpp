#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include "DaThuc.h"

using namespace std;

int main()
{
	DaThuc A;
	A.nhap();
	cout << endl;
	cout << "Da thuc da nhap la: ";
	A.xuat();
	cout << endl;
	A.Tinhdathuc();
	cout << endl;
	DaThuc B;
	B.nhap();
	DaThuc c;

	c = A.Congdathuc(B);
	cout << "Tong cua hai da thuc la: ";
	c.xuat();
	cout << endl;

	c = A.Trudathuc(B);
	cout << "Hieu cua hai da thuc la: ";
	c.xuat();
	cout << endl;
	return 0;
}

