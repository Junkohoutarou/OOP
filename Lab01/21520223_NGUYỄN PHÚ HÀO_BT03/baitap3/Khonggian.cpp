#include "Khonggian.h"
#include <iostream>
#include <algorithm>
#include <cmath>

void khonggian::nhap() 
{
	cout << "Vui long nhap toa do x:";
	cin >> x;
	cout << "Vui long nhap toa do y:";
	cin >> y;
};

void khonggian::xuat() 
{
	cout << "Toa do cua diem vua nhap la: " << "(" << x << "," << y << ")" << endl;
}


int khonggian::khoangcach(khonggian a) {
	float c, d, e;
	c = x - a.x;
	d = y - a.y;
	e = c * c + d * d;
	cout << "Khoang cach giua 2 diem vua nhap la:" << sqrt(e);
	return 0;
}