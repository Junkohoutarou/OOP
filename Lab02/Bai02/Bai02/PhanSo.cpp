#include <iostream>
#include <cstring>
#include <stdio.h>


#include "PhanSo.h"

using namespace std;


void PhanSo::Nhap() {
    cout << "Nhap tu so: ";
    cin >> TuSo;
    do
    {
        cout << "Nhap mauso: ";
        cin >> MauSo;
    } while (MauSo == 0);
    ToiGian_PhanSo();
}

void PhanSo::xuat() {
    if (MauSo == 1) { cout << TuSo << endl; }
    else { cout << TuSo << "/" << MauSo << endl; }
}

void PhanSo::Xuat() {
    if (MauSo == 1) { cout << "Phan so cua ban la: " << TuSo << endl; }
    else { cout << "Phan so cua ban la: " << TuSo << "/" << MauSo << endl; }
}

void PhanSo::Thapphan() {
    double c;
    c = (TuSo * 1.0) / MauSo;
    cout << "Phan so duoi dang thap phan: " << c << endl;
}

PhanSo PhanSo::Cong(PhanSo P)
{
    PhanSo kq; //Kq của tổng hai phân số 
    kq.TuSo = TuSo * P.MauSo + P.TuSo * MauSo;
    kq.MauSo = MauSo * P.MauSo;
    kq.ToiGian_PhanSo();
    return kq;
}

PhanSo PhanSo::Tru(PhanSo P)
{
    PhanSo kq; //Kq của tổng hai phân số 
    kq.TuSo = TuSo * P.MauSo - P.TuSo * MauSo;
    kq.MauSo = MauSo * P.MauSo;
    kq.ToiGian_PhanSo();
    return kq;
}

PhanSo PhanSo::Nhan(PhanSo P)
{
    PhanSo kq; //Kq của tổng hai phân số 
    kq.TuSo = TuSo * P.TuSo;
    kq.MauSo = MauSo * P.MauSo;
    kq.ToiGian_PhanSo();
    return kq;
}
PhanSo PhanSo::Chia(PhanSo P)
{
    PhanSo kq; //Kq của tổng hai phân số 
    kq.TuSo = TuSo * P.MauSo;
    kq.MauSo = MauSo * P.TuSo;
    kq.ToiGian_PhanSo();
    return kq;
}

PhanSo::~PhanSo() {};