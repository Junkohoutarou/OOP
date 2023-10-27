//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b){  // Tim uoc chung nho nhat
    if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b;
        }else{
            b -= a;
        }
    }
    return a;
}

class PhanSo{
   private:
       int TuSo;
       int MauSo;
   public:
        PhanSo(){
            TuSo = 0;
            MauSo = 1;
        }
        PhanSo (int a)
        {
           TuSo = a;
           MauSo = 1;
        }
        PhanSo(int Tu, int Mau)
        {
           this->TuSo = Tu;
           this->MauSo = Mau;
        }
        PhanSo(const PhanSo &P)
        {
           TuSo = P.TuSo;
           MauSo = P.MauSo;
        }
        void ToiGian_PhanSo(){ //Toi gian hoa phan so
            if (MauSo==0) return;

                int a , b;
                if (TuSo * MauSo <0)
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
                    TuSo = a/ucln;
                    MauSo= b/ucln;
                }

        friend ostream& operator<<(ostream& os, PhanSo P) // Xuat PhanSo
        {
           P.ToiGian_PhanSo();
           if (P.MauSo==1) {os << P.TuSo << endl; return os;}
           os << P.TuSo << "/" << P.MauSo << endl;
           return os;
        }

        friend istream& operator>>(istream& is, PhanSo& P) // Nhap PhanSo
        {
           cout << "Moi Nhap TuSo: "; is >> P.TuSo;
           cout << "Moi Nhap MauSo: "; is >> P.MauSo;
           return is;
        }
        friend PhanSo operator +(PhanSo a, PhanSo b)
        {
           PhanSo c; // Phan so phu
           //Tinh tong
           c.TuSo = a.TuSo*b.MauSo + b.TuSo*a.MauSo;
           c.MauSo = a.MauSo * b.MauSo;
           return c;
        }

        friend PhanSo operator -(PhanSo a, PhanSo b)
        {
           PhanSo c; // Phan so phu
           //Tinh hieu
           c.TuSo = a.TuSo*b.MauSo - b.TuSo*a.MauSo;
           c.MauSo = a.MauSo * b.MauSo;
           return c;
        }

        friend PhanSo operator*(PhanSo a, PhanSo b)
        {
           PhanSo c; // Phan so phu
           //Tinh hieu
           c.TuSo = a.TuSo * b.TuSo;
           c.MauSo = a.MauSo * b.MauSo;
           return c;
        }

        friend PhanSo operator/(PhanSo a, PhanSo b)
        {
           PhanSo c; // Phan so phu
           //Tinh thuong
           c.TuSo = a.TuSo * b.MauSo;
           c.MauSo = a.MauSo * b.TuSo;
           return c;
        }
        void operator += (PhanSo ps)
        {
            TuSo = this->TuSo*ps.MauSo + ps.TuSo*this->MauSo;
            MauSo = this->MauSo * ps.MauSo;
        }
        void operator -= (PhanSo ps)
        {
            TuSo = this->TuSo * ps.MauSo - ps.TuSo * this->MauSo;
            MauSo = this->MauSo * ps.MauSo;
        }
        void operator *= (PhanSo ps)
        {
            TuSo = this->TuSo * ps.TuSo;
            MauSo = this->MauSo * ps.MauSo;
        }
        void operator /= (PhanSo ps)
        {
            TuSo = this->TuSo / ps.TuSo;
            MauSo = this -> MauSo / ps.MauSo;
        }
        bool operator == (const PhanSo &ps)
        {
            int ketqua = this->TuSo * ps.MauSo - this->MauSo * ps.TuSo;
            if (ketqua == 0)return true;
            return false;
        }
        bool operator < (const PhanSo& a)
        {
            int kq = TuSo * a.MauSo - a.TuSo * MauSo;
            if (kq < 0)return true;
            return false;
        }
        bool operator > (const PhanSo& a)
        {
            int kq = TuSo * a.MauSo - a.TuSo * MauSo;
            if (kq > 0)return true;
            return false;
        }
        bool operator >= (const PhanSo& a)
        {
            int kq = TuSo * a.MauSo - a.TuSo * MauSo;
            if (kq >= 0)return true;
            return false;
        }
        bool operator <= (const PhanSo& a)
        {
            int kq = TuSo * a.MauSo - a.TuSo * MauSo;
            if (kq <= 0)return true;
            return false;
        }
        bool operator != (const PhanSo& a)
        {
            int kq = TuSo * a.MauSo - a.TuSo * MauSo;
            if (kq != 0)return true;
            return false;
        }
         PhanSo operator ++ (int x)
        {
            PhanSo kq(*this);
            this->TuSo = this->TuSo + this->MauSo;
            return kq;
        }
          PhanSo operator -- (int x)
        {
            PhanSo kq(*this);
            this->TuSo = this->TuSo - this->MauSo;
            return kq;
        }
};



int main()
{
    PhanSo Frac1;
    cin >> Frac1;
    PhanSo Frac2;
    cin >> Frac2;
    cout << Frac2;
    cout << Frac1 + Frac2;
    cout << Frac1 - Frac2;
    cout << Frac1 * Frac2;
    cout << Frac1 / Frac2;
    if (Frac1 == Frac2) {cout << "Hai phan so da cho bang nhau";} else {cout << "Hai phan so da cho khong bang nhau";}
    cout << endl;

    return 0;
}
