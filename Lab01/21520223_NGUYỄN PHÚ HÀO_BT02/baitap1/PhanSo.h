#pragma once

#include <iostream>
#include <cstring>
#include <stdio.h>



using namespace std;	


class PhanSo{
	private:
		int TuSo;
		int MauSo;
	public:
		PhanSo() {
			TuSo = 0;
			MauSo = 1;
		};
        PhanSo(int a)
        {
            TuSo = a;
            MauSo = 1;
        };
        PhanSo(int Tu, int Mau)
        {
            this->TuSo = Tu;
            this->MauSo = Mau;
        };
        PhanSo(const PhanSo& P)
        {
            TuSo = P.TuSo;
            MauSo = P.MauSo;
        };
        int gcd(int a, int b) {  // Tìm ước chung lớn nhất
            if (a == 0 || b == 0) {
                return a + b;
            }
            while (a != b) {
                if (a > b) {
                    a -= b;
                }
                else {
                    b -= a;
                }
            }
            return a;
        }
        void ToiGian_PhanSo() { //Toi gian hoa phan so
            if (MauSo == 0) return;

            int a, b;
            if (TuSo * MauSo < 0)
            {
                a = abs(TuSo) * -1;
                b = abs(MauSo);
            }
            else
            {
                a = abs(TuSo);
                b = abs(MauSo);
            }
              int ucln = gcd(abs(a), abs(b));
              TuSo = a / ucln;
              MauSo = b / ucln;
        };
		void Nhap();
        void xuat();
		void Xuat();
		void Thapphan();
        PhanSo Cong(PhanSo x);
        PhanSo Tru(PhanSo x);
        PhanSo Nhan(PhanSo x);
        PhanSo Chia(PhanSo x);
};