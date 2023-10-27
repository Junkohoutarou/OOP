#include "sophuc.h"
#include <iostream>
#include <algorithm>
#include <cmath>

void sophuc::nhap() {
	cout << "Vui long nhap so thuc:";
	cin >> thuc;
	cout << "Vui long nhap so ao:";
	cin >> ao;
}

void sophuc::xuat() {

	if (ao == 0 && thuc == 0) cout << "So phuc vua nhap la: 0" << endl;
	if (ao == 0 && thuc != 0) cout << "so phuc vua nhap la:" << thuc << endl;
	if (thuc == 0 && ao != 0)
	{
		if (ao == -1) cout << "so phuc vua nhap la:" << thuc << "-i" << endl;
		else if (ao == 1) cout << "so phuc vua nhap la:" << thuc << "i" << endl;
		else cout << "so phuc vua nhap la:" << ao << "i" << endl;
	}
	
	if (thuc != 0 && abs(ao) != 1)   {
		if (ao > 0) cout << "so phuc vua nhap la:" << thuc << " + " << ao << "i" << endl;
		else if (ao < 0)  cout << "so phuc vua nhap la:" << thuc << " - " << abs(ao) << "i" << endl;
	}
	else if (thuc != 0 && abs(ao) == 1) {
		if (ao == 1) cout << "so phuc vua nhap la:" << thuc << " + " << "i" << endl;
		else if (ao == -1)  cout << "so phuc vua nhap la:" << thuc << " - " << "i" << endl;
	}
	
}

void sophuc::Xuat() {

	if (ao == 0 && thuc == 0) cout << 0 << endl;
	if (ao == 0 && thuc != 0) cout << thuc << endl;
	if (thuc == 0 && ao != 0)
	{
		if (ao == -1) cout << thuc << "-i" << endl;
		else if (ao == 1) cout << thuc << "i" << endl;
		else cout << ao << "i" << endl;
	}

	if (thuc != 0 && abs(ao) != 1) {
		if (ao > 0) cout << thuc << " + " << ao << "i" << endl;
		else if (ao < 0)  cout  << thuc << " - " << abs(ao) << "i" << endl;
	}
	else if (thuc != 0 && abs(ao) == 1) {
		if (ao == 1) cout  << thuc << " + " << "i" << endl;
		else if (ao == -1)  cout << thuc << " - " << "i" << endl;
	}

}

sophuc sophuc::tong(sophuc x) {
	sophuc kq;
	kq.thuc = thuc + x.thuc;
	kq.ao = ao + x.ao;
	return kq;
}
	
sophuc sophuc::hieu(sophuc x) {
	sophuc kq;
	kq.thuc = thuc - x.thuc;
	kq.ao = ao - x.ao;
	return kq;
}

sophuc sophuc::tich(sophuc x) {
	sophuc kq;
	kq.thuc = thuc * x.thuc - ao * x.ao ;
	kq.ao = thuc * x.ao + x.thuc + ao ; 
	return kq;
}

sophuc sophuc::thuong(sophuc x) {
	sophuc kq;
	kq.thuc = ((thuc * x.thuc + ao * x.ao) * 1.0) / (x.thuc * x.thuc + x.ao * x.ao);
	kq.ao = ((x.thuc * ao - x.ao * thuc) * 1.0) / (x.thuc * x.thuc + x.ao * x.ao);
	return kq;
}


