#include "Candidate.h"
#include <iostream>

using namespace std;

void Candidate::Input()
{
	cin.ignore();
	cout << "Nhap ma so thi sinh: ";
	getline(cin, Ma);
	cout << "Nhap ho ten thi sinh: ";
	getline(cin, HoTen);
	cout << "Nhap ngay sinh cua thi sinh: ";
	getline(cin, NgaySinh);
	cout << "Nhap diem Toan cua thi sinh: ";
	cin >> Toan;
	cout << "Nhap diem Van cua thi sinh: ";
	cin >> Van;
	cout << "Nhap diem Anh cua thi sinh: ";
	cin >> Anh;
}

void Candidate::Output()
{
	cout << "Thong tin thi sinh: " << endl;
	cout << "	Ma so thi sinh: " << Ma << endl;
	cout << "	Ho va Ten: " << HoTen << endl;
	cout << "	Ngay sinh: " << NgaySinh << endl;
	cout << "Diem cua thi sinh: ";
	cout << "\n\tToan: " << Toan << "\n\tVan: " << Van << "\n\tAnh: " << Anh << endl;
	cout << "----------------*----------------\n";
}

bool Candidate::Check()
{
	int tb = Toan + Van + Anh;
	if (tb >= 15)
		return 1;
	else
		return 0;
}