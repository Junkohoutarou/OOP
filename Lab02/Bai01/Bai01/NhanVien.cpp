#include"NhanVien.h"
#include <iostream>
#include<string>
#include<iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
string NhanVien::gethoten()
{
	return hoten;
}
void NhanVien::setHoten(string t)
{
	hoten = t;
}
int NhanVien::getsongay()
{
	return songay;
}
void NhanVien::setSongay(int sn)
{
	songay = sn;
}
void NhanVien::setmaso(string t, int sn)
{
	to_string(sn);
}
string NhanVien::getmaso()
{
	return maso;
}
string NhanVien::getchucdanh()
{
	return chucdanh;
}
void NhanVien::setchucdanh(int sn)
{
	if (sn > 0 && sn < 365)chucdanh = "Nhan Vien";
	if (sn >= 365 && sn < 730)chucdanh = "Quan Ly";
	if (sn >= 730 && sn < 1460)chucdanh = "Truong Phong";
	if (sn >= 1460)chucdanh = "Truong ban quan ly";
}
string NhanVien::gethesoluong()
{
	return hesoluong;
}
void NhanVien::sethesoluong()
{
	if (chucdanh == "Nhan Vien")hesoluong = "1.0";
	if (chucdanh == "Quan Ly")hesoluong = "1.5";
	if (chucdanh == "Truong Phong")hesoluong = "2.25";
	if (chucdanh == "Truong ban quan ly")hesoluong = "4.0";
}
NhanVien::NhanVien(string t, int sn, string ms, string cd, string hsl)
{
	hoten = t;
	songay = sn;
	maso = ms;
	chucdanh = cd;
	hesoluong = hsl;

}
NhanVien::NhanVien(string t, int sn)
{
	hoten = t;
	songay = sn;
}
void NhanVien::Xuat(string t, int sn)
{
	cout << "\tThong tin cua nhan vien: " << endl;
	cout << "+ Ho va ten: " << gethoten() << endl;
	cout << "+ So ngay lam viec: " << getsongay() << endl;
	cout << "+ Ma so cua nhan vien: " << sn << t << endl;
	cout << "+ Chuc danh: " << getchucdanh() << endl;
	cout << "+ He so luong: " << gethesoluong() << endl;
}
void NhanVien::Xuat()
{
	cout << "\tThong tin cua nhan vien: " << endl;
	cout << "+ Ho va ten: " << gethoten() << endl;
	cout << "+ So ngay lam viec: " << getsongay() << endl;
	cout << "+ Ma so cua nhan vien: " << getmaso() << endl;
	cout << "+ Chuc danh: " << getchucdanh() << endl;
	cout << "+ He so luong: " << gethesoluong() << endl;
}
void NhanVien::Nhap(string& ten, int& sn)
{
	cout << "Moi nhap thong tin nhan vien: " << endl;
	cout << "Nhap ten: ";
	getline(cin, ten);
	setHoten(ten);
	cout << "Nhap so ngay lam viec: ";
	cin >> sn;
	setSongay(sn);
	setchucdanh(sn);
	sethesoluong();

}
NhanVien::NhanVien()
{
	hoten = "Phat";
	songay = 366;
	maso = "366Hao";
	chucdanh = "Quan Ly";
	hesoluong = "1.5";

}
NhanVien::NhanVien(const NhanVien& temp)
{
	chucdanh = temp.chucdanh;
	hesoluong = temp.hesoluong;
	songay = temp.songay;
	hoten = "Phat";
	maso = "366Phat";
}
NhanVien::~NhanVien() {};