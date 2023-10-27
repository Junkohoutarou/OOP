#include "Classroom.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
int main()
{
	fstream myfile;
	myfile.open("Lophoc.txt", fstream::in | fstream::app);
	Lophoc a;
	int n;
	myfile >> n;
	for (int i = 1; i <= n; ++i)
	{
		Hocsinh x;
		myfile.ignore();
		getline(myfile, x.hoten);
		myfile >> x.maso;
		myfile.ignore();
		getline(myfile, x.sdt);
		myfile >> x.dtb;
		a.addhocsinh(x);
	}
	cout << "========================================\n";
	cout << "----------------------------------------\n";
	a.printallhocsinh();
	cout << "----------------------------------------\n";
	while (true)
	{
		cout << "==================MENU==================\n";
		cout << "1. Them Hoc sinh. \n";
		cout << "2. Xoa Hoc sinh. \n";
		cout << "3. Xuat toan bo hoc sinh. \n";
		cout << "4. In ra hoc sinh co diem trung binh tren 8. \n";
		cout << "==================END===================\n";
		cout << "Nhap lua chon: ";
		int x;
		cin >> x;
		cout << "----------------------------------------\n";
		switch (x)
		{
		case 1:
		{
			cout << "Moi Nhap: \n";
			Hocsinh x;
			x.Nhap();
			if (a.kttrunglap(x))

				cout << "\nDa co hoc sinh trong lop.\nKet qua: Them hoc sinh that bai.\n";
			else
			{
				a.addhocsinh(x);
				cout << "\nKet qua: Them hoc sinh thanh cong. \n";
			}
			cout << "----------------------------------------\n";
			break;
		}
		case 2:
		{
			cout << "Moi Nhap: \n";
			Hocsinh x;
			x.Nhap();
			if (a.kttrunglap(x))
			{
				a.deletehocsinh(x);
				cout << "Ket qua: Xoa hoc sinh thanh cong. \n";
			}
			else cout << "Xoa hoc sinh that bai.\nKhong co hoc sinh trong lop. \n";
			break;
			cout << "----------------------------------------\n";
		}
		case 3:
		{
			a.printallhocsinh();
			cout << "----------------------------------------\n";
			break;
		}
		case 4:
		{
			a.xuathocsinhdtbtren8();
			cout << "----------------------------------------\n";
			break;
		}
		default:
			break;
		}
	}
}
