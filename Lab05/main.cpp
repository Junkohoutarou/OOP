#include<iostream>
#include<string>
#include<vector>
#define MAX 100
using namespace std;
class Nhanvien
{
protected:
	string hoten;
	string ngaysinh;
	string maso;
public:
	Nhanvien()
	{
		hoten = "Nguyen Phu Hao";
		ngaysinh = "09/07/2002";
		maso = "21520223";
	}
	Nhanvien(string ten, string ns, string ms)
	{
		hoten = ten;
		ngaysinh = ns;
		maso = ms;
	}
};
class Giangvien :protected Nhanvien
{
private:
	string hocham;
	string hocvi;
	int sonamgd;
	int somonhocgd;
	string tenmonhoc;
	long double luong;
	void tinhluong()
	{
		luong = (sonamgd * somonhocgd * 0.12) * 20000;
	}
public:
	Giangvien()
	{
		hocham = "Ky su";
		hocvi = "Pho giao su";
		sonamgd = 30;
		somonhocgd = 3;
		tenmonhoc = "XSTK,OOP,DSA";
		luong = 500000;
	}
	Giangvien(string ten,string ns,string ms,string hh, string hv, int sonam, int somon, long double tienthuong, string monhoc) :Nhanvien(ten,ns,ms)
	{
		hocham = hh;
		hocvi = hv;
		sonamgd = sonam;
		somonhocgd = somon;
		luong = tienthuong;
		tenmonhoc = monhoc;
	}
	void nhapgv()
	{
		getline(cin, hoten);
		getline(cin, ngaysinh);
		getline(cin, maso);
		getline(cin, hocham);
		getline(cin, hocvi);
		cin >> sonamgd;
		cin >> somonhocgd;
		cin.ignore();
		getline(cin, tenmonhoc);
		tinhluong();

	}
	void xuatgv()
	{
		cout << hoten<<endl;
		cout << ngaysinh<<endl;
		cout << maso << endl;;
		cout << hocham<<endl;
		cout << hocvi<<endl;
		cout << sonamgd<<endl;
		cout << somonhocgd<<endl;
		cout << tenmonhoc<<endl;
		cout << luong<<endl;
	}

};
class Trogiang :protected Nhanvien
{
private:
	int somontrogiang;
	long double luong;
	void tinhluong()
	{
		luong = (somontrogiang * 0.3) * 18000;
	}
public:
	Trogiang()
	{
		hoten = "Nguyen Phu Hao";
		ngaysinh = "09/07/2002";
		maso = "21520223";
		somontrogiang = 3;
		luong = 100000;
	}
	Trogiang(int somon, long double tienluong) :Nhanvien(hoten, ngaysinh, maso)
	{
		somontrogiang = somon;
		luong = tienluong;
	}
	void nhaptg()
	{

		getline(cin, hoten);
		getline(cin, ngaysinh);
		getline(cin, maso);
		cin >> somontrogiang;
		tinhluong();
	}
	void xuattg()
	{
		cout << hoten<<endl;
		cout << ngaysinh<<endl;
		cout << maso<<endl;
		cout << somontrogiang<<endl;
		cout << luong<<endl;
	}
};
class Ncv :protected Nhanvien
{
private:
	string duan;
	long double luong;
	int sonamnc;
	int soduan()
	{
		int count = 0;
		for (int i = 0; i < duan.length(); i++)
		{
			if (duan[i] == 'D')count++;
		}
		return count;
	}
	void tinhluong()
	{
		luong = (sonamnc * 2 + soduan()) * 20000;
	}
public:
	Ncv()
	{
		hoten = "Nguyen Phu Hao";
		ngaysinh = "09/07/2002";
		maso = "21520223";
		duan = "D89,H78";
		sonamnc = 5;
		luong = 700000;
	}
	void nhapncv()
	{

		getline(cin, hoten);
		getline(cin, ngaysinh);
		getline(cin, maso);
		getline(cin, duan);
		cin >> sonamnc;
		tinhluong();
	}
	void xuatncv()
	{
		cout << hoten<<endl;
		cout << ngaysinh<<endl;
		cout << maso<<endl;
		cout << duan<<endl;
		cout << sonamnc<<endl;
		cout << luong<<endl;
	}
};
class chuyenvien :protected Nhanvien
{
private:
	string duan;
	long double luong;
	int sonamlm;
	int soduan()
	{
		int count = 0;
		for (int i = 0; i < duan.length(); i++)
		{
			if (duan[i] == 'T')count++;
		}
		return count;
	}
	void tinhluong()
	{
		luong = (sonamlm * 4 + soduan()) * 18000;
	}
public:
	chuyenvien()
	{
		hoten = "Nguyen Phu Hao";
		ngaysinh = "09/07/2002";
		maso = "21520223";
		duan = "T89,H78";
		sonamlm = 5;
		luong = 800000;
	}
	void nhapcv()
	{

		getline(cin, hoten);
		getline(cin, ngaysinh);
		getline(cin, maso);
		getline(cin, duan);
		cin >> sonamlm;
		tinhluong();
	}
	void xuatcv()
	{
		cout << hoten<<endl;
		cout << ngaysinh<<endl;
		cout << maso<<endl;
		cout << duan<<endl;
		cout << sonamlm<<endl;
		cout << luong<<endl;
	}
};
int main()
{
	Giangvien gv;
	gv.nhapgv();
	gv.xuatgv();
	Trogiang tg;
	tg.nhaptg();
	tg.xuattg();
	Ncv ncv;
	ncv.nhapncv();
	ncv.xuatncv();
	chuyenvien cv;
	cv.nhapcv();
	cv.xuatcv();
}


