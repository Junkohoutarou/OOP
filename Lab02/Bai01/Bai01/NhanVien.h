#pragma once
#include <iostream>
#include<string>
#include<iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class NhanVien
{
private:
	string hoten;
	int songay;
	string maso;
	string chucdanh;
	string hesoluong;
public:
	void Xuat(string ten, int sn);
	void Nhap(string& ten, int& sn);
	void Xuat();
	string gethoten();
	void setHoten(string t);
	int getsongay();
	void setSongay(int songay);
	void setmaso(string t, int sn);
	string getmaso();
	string getchucdanh();
	void setchucdanh(int sn);
	string gethesoluong();
	void sethesoluong();
	NhanVien();
	NhanVien(string ten, int ngay, string ma, string cd, string hsl);
	NhanVien(string t, int sn);
	NhanVien(const NhanVien& temp);
	~NhanVien();
};
