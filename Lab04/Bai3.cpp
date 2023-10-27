#include <iostream>
#include <cmath>
#include <cstring>
//#include <bits/stdc++.h>

using namespace std;

class MangSoNguyen
    {
        private:
            int kichthuoc;
            int* dulieu;
        public:
        void setdulieu(int x)
            {
                *this->dulieu = x;
            }
        int getdulieu(int x)
            {
                return dulieu[x];
            }
        int getkichthuoc()
            {
                return kichthuoc;
            }
        void setkichthuoc(int x)
            {
                this->kichthuoc = x;
            }
        MangSoNguyen()
            {
                kichthuoc = 2;
                dulieu = new int[2];
            }
        MangSoNguyen(const MangSoNguyen& x)
            {
                kichthuoc = x.kichthuoc;
                dulieu = new int[kichthuoc];
                for (int i = 0; i < kichthuoc; i++)
                    {
                        dulieu[i] = x.dulieu[i];
                    }
            }
        MangSoNguyen(int x, int y)
            {
                kichthuoc = x;
                dulieu = new int[x];
                for (int i = 0; i < x; i++)
                    {
                        dulieu[i] = y;
                    }

            }
        friend istream& operator >> (istream& in, MangSoNguyen& a)
            {
                cout << "Nhap so phan tu: ";
                in >> a.kichthuoc;
                a.dulieu = new int[a.kichthuoc];
                for (int i = 0; i < a.kichthuoc; i++)
                    {
                        cout << "Nhap phan tu so " << i + 1 << " : ";
                        in >> a.dulieu[i];
                    }
                return in;
            }
        friend ostream& operator <<(ostream& out, MangSoNguyen a)
            {
                for (int i = 0; i < a.kichthuoc; i++)
                    {
                        out << "Phan tu so " << i + 1 << " : ";
                        out << a.dulieu[i] << endl;
                    }
                return out;
            }
        void operator =(MangSoNguyen a)
            {
                delete[]dulieu;
                dulieu = NULL;
                kichthuoc = a.kichthuoc;
                dulieu = new int[kichthuoc];
                cout << "TOAN TU =" << endl;
                for (int i = 0; i < kichthuoc; i++)
                    {
                        dulieu[i]=a.dulieu[i];
                    }
            }
        friend MangSoNguyen operator +(MangSoNguyen a, MangSoNguyen b)
            {
                cout << "---TONG--- " << endl;;
                MangSoNguyen c;
                delete[]c.dulieu;
                c.dulieu = NULL;
                c.dulieu = new int[c.kichthuoc];
                c.kichthuoc = (a.kichthuoc >= b.kichthuoc) ? a.kichthuoc : b.kichthuoc;
                if (c.kichthuoc == a.kichthuoc)
                    {
                        for (int i = 0; i < b.kichthuoc; i++)
                            {

                                c.dulieu[i] = a.dulieu[i] + b.dulieu[i];
                            }
                        for (int j = b.kichthuoc; j < c.kichthuoc; j++)
                            {

                                c.dulieu[j] = a.dulieu[j];
                            }
                    }
		else if (b.kichthuoc == a.kichthuoc)
            {
                for (int i = 0; i < b.kichthuoc; i++)
                    {
                        c.dulieu[i] = a.dulieu[i] + b.dulieu[i];
                    }
            }
		else if (c.kichthuoc==b.kichthuoc)
            {
                for (int i = 0; i < a.kichthuoc; i++)
                {
                    c.dulieu[i] = b.dulieu[i] + a.dulieu[i];
                }
                for (int j = a.kichthuoc; j < c.kichthuoc; j++)
                {
                    c.dulieu[j] = b.dulieu[j];
                }
            }
		return c;
	}
	void operator ++()
	{
		for (int i = 0; i < kichthuoc; i++)
		{
			dulieu[i] ++;
		}
	}
	MangSoNguyen operator ++(int x)
	{
		MangSoNguyen temp;
		temp = *this;
		for (int i = 0; i < kichthuoc; i++)
		{
			dulieu[i] ++;
		}
		return temp;
	}
		~MangSoNguyen() {};
	};

int main(){

		MangSoNguyen arrayA, arrayB , arrayC , arrayD ;
		cin >> arrayA >>  arrayB;
		arrayC = arrayA + arrayB;
		cout << arrayC;
		arrayD = arrayA;
		cout << arrayD;

		return 0;
}
