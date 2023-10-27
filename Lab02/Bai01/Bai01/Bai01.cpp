#include "NhanVien.h"
#include <iostream>
#include <algorithm>
#include <cmath>


int main()
{
	string ten = "Phat", t;
	int sn = 800, ngay;
	NhanVien a("Tuan", 30, "30Tuan", "Nhan Vien", "1.0");
	a.Xuat("Tuan", 30);
	NhanVien b(ten, sn);//Tao lap 2 tham so 
	b.setchucdanh(sn);
	b.sethesoluong();
	b.Xuat(ten, sn);
	NhanVien c;//
	c.Nhap(t, ngay);
	c.Xuat(t, ngay);
	NhanVien d(c);
	d.Xuat();
}







