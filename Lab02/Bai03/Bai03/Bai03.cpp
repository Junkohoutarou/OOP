#include"DanhSachPhanSo.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

void menu()
{
	cout << "\t1.Tinh tong cac phan so" << endl;
	cout << "\t2.Tim phan so lon nhat" << endl;
	cout << "\t3.Tim phan so nho nhat" << endl;
	cout << "\t4.Sap xep phan so theo thu tu tang dan" << endl;
	cout << "\t5.Sap xep phan so theo thu tu giam dan" << endl;
	cout << "\t0.Thoat chuong trinh" << endl;
	cout << "\t\t Moi nhap yeu cau: ";
}
int main()
{
	DSPhanso A, c, max, min, g, t;
	DSPhanso a[200];
	int n;
	cout << "Nhap so luong phan so can tinh: ";
	cin >> n;
	A.nhap(a, n);
	cout << "Cac phan so vua nhap la: ";
	A.xuat(a, n);
	cout << endl;
	menu();
	int Cau;
	do
	{
		cout << endl << "Vui long nhap cau hoi ban muon tra loi: ";
		cin >> Cau;
		switch (Cau)
		{
		case 1:
		{
			c = A.cong(a, n);
			cout << "Tong cac phan so la: ";
			c.Xuat1PS();
			break;
		}
		case 2:
		{
			cout << "Phan so lon nhat la: ";
			max = A.phansomax(a, n);
			max.Xuat1PS();
			break;
		}
		case 3:
		{
			cout << "Phan so nho nhat la: ";
			min = A.phansomin(a, n);
			min.Xuat1PS();
			break;
		}
		case 4:
		{
			cout << "Cac phan so sau khi sap xep tang dan: ";
			A.tangdan(a, n);
			A.xuat(a, n);
			break;
		}
		case 5:

		{
			cout << "Cac phan so sau khi sap xep giam dan la: ";
			A.giamdan(a, n);
			A.xuat(a, n);
			break;
		}
		default: cout << "Chon sai menu" << endl;
		}
	} while (Cau != 0);
			
	
	return 0;
}