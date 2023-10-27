#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class cb
{
protected:
	int maso;
	string hoten;
	string ngaysinh;
public:
	virtual double luong() = 0;
	virtual void in()
	{
		cin.ignore();
		cout << "Moi nhap ho ten: ";
		getline(cin, hoten);
		cout << endl;
		cout << "Moi nhap ma so can bo: ";
		cin >> maso;
		cout << endl;
		cin.ignore();
		cout << "Moi nhap ngay sinh gom 2 chu so: ";
		getline(cin, ngaysinh);
		cout << endl;
	}
	virtual void out()
	{
		cout << "Ho ten can bo: " << hoten << endl;
		cout << "Ma so can bo: " << maso << endl;
		cout << "Ngay sinh cua can bo: " << ngaysinh << endl;
	}
	virtual int type() = 0;
	virtual ~cb() {};
};
class cbbienche :public cb
{
private:
	double luongcoban;
	float hsluong;
	float hsphucap;

public:
	double luong()
	{
		double l;
		l = luongcoban * hsluong * hsphucap;
		return l;
	}
	void in()
	{
		cb::in();
		cout << "Moi nhap luong co ban: ";
		cin >> luongcoban;
		cout << endl;
		cout << "Moi nhap he so luong: ";
		cin >> hsluong;
		cout << endl;
		cout << "Moi nhap he so phu cap: ";
		cin >> hsphucap;
	}
	void out()
	{
		cb::out();
		cout << "Luong cua can bo: " << luong() << endl;
	}
	int type()
	{
		return 1;
	}
};
class cbhopdong :public cb
{
private:
	double tiencong;
	float songaycong;
	float hesovuotgio;
public:
	double luong()
	{
		double l;
		l = tiencong * songaycong * hesovuotgio;
		return l;
	}
	void in()
	{
		cb::in();
		cout << "Moi nhap tien cong: ";
		cin >> tiencong;
		cout << endl;
		cout << "Moi nhap so ngay cong: ";
		cin >> songaycong;
		cout << endl;
		cout << "Moi nhap he so vuot gio: ";
		cin >> hesovuotgio;
		cout << endl;
	}
	void out()
	{
		cb::out();
		cout << "Luong cua can bo: " << luong() << endl;
	}
	int type()
	{
		return 2;
	}
};
int main()
{
	cb* a[1000];
	int n, k;
	cout << "Nhap so luong can bo: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Moi nhap kieu can bo: " << endl;
		cout << "1. Can bo bien che." << endl;
		cout << "2. Can bo hop dong." << endl;
		cin >> k;
		if (k == 1)
		{
			a[i] = new cbbienche;
			a[i]->in();
		}
		if (k == 2)
		{
			a[i] = new cbhopdong;
			a[i]->in();
		}
	}
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->type() == 1)
		{
			cout << "\tCan bo bien che: " << endl;
			a[i]->out();
		}
		if (a[i]->type() == 2)
		{
			cout << "\tCan bo hop dong: " << endl;
			a[i]->out();
		}
		sum += a[i]->luong();
	}
	cout << "Tong luong ma cong ty ABC can phai tra la: " << sum;
	return 0;

}