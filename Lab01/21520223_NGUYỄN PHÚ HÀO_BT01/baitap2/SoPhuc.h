#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
class sophuc {
public:
	float ao;
	float thuc;
public:
	void nhap();
	void xuat();
	void Xuat();
	sophuc tong(sophuc x);
	sophuc hieu(sophuc x);
	sophuc tich(sophuc x);
	sophuc thuong(sophuc x);
};