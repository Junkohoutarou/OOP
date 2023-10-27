//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

class SoPhuc
{
private:
	float sothuc;
	float soao;
public:
	SoPhuc()
	{
		sothuc = 0;
		soao = 1;
	}
	SoPhuc(int x, int y)
	{
		sothuc = x;
		if (y != 0)
		{
			soao = y;
		}
		else
		{
			cout << "Khong phai la so phuc" << endl;
			soao = 0;
		}
	}
	~SoPhuc()
	{
		sothuc = 0;
		soao = 1;
	}
friend istream& operator >> (istream& in, SoPhuc& a)
{
    cout << "Nhap so thuc: ";
    in >> a.sothuc;
    cout << "Nhap so ao: ";
    in >> a.soao;
    return in;
}
friend ostream& operator<<(ostream& out, SoPhuc a)
{
    if (a.soao < 0) cout << a.sothuc << a.soao << "i" << endl;
    else if (a.soao > 0)
        out << a.sothuc << "+" << a.soao << "i" << endl;
    else cout << a.sothuc<<endl;
    return out;
}
friend SoPhuc operator +(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
        c.sothuc = a.sothuc + b.sothuc;
        c.soao = a.soao + b.soao;
        return c;
}
friend SoPhuc operator -(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.sothuc = a.sothuc - b.sothuc;
    c.soao = a.soao - b.soao;
    return c;
}
friend SoPhuc operator *(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.sothuc=(a.sothuc * b.sothuc-a.soao*b.soao);
    c.soao = a.sothuc * b.soao + a.soao * b.sothuc;
    return c;
}
friend SoPhuc operator /(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.sothuc = float((a.sothuc * b.sothuc + a.soao * b.soao)*1.0/(pow(b.sothuc,2)+pow(b.soao,2)));
    c.soao = float((a.soao * b.sothuc - a.sothuc * b.soao)*1.0 / (pow(b.sothuc, 2) + pow(b.soao, 2)));
    return c;
}
bool operator == (const SoPhuc& a)
{
    if (sothuc - a.sothuc == 0 && soao - a.soao == 0) return true;
    return false;
}
bool operator != (const SoPhuc& a)
{
    if (sothuc - a.sothuc == 0 && soao - a.soao != 0) return true;
    return false;
}

};

int main()
{
   	SoPhuc a,b;
	cin >> a>>b;
	SoPhuc c = a+b;
	SoPhuc d = a - b;
	SoPhuc e = a * b;
	SoPhuc g = a / b;
	cout << c ;
	cout << d;
	cout << e;
	cout << g;
	if (a == b) cout << "Hai so phuc bang nhau";
	else cout << "Hai so phuc khong bang nhau";
    return 0;
}
