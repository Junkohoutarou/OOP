#include <iostream>
#include <string>
using namespace std;
class NhanVien
{
protected:
	string ma;
	string hovaten;
	string ngaysinh;
public:
	virtual void Nhap()
	{
		cout << "Nhap ma so nhan vien: ";
		getline(cin, ma);
		cout << "Nhap ho va ten nhan vien: ";
		getline(cin, hovaten);
		cout << "Nhap ngay/thang/nam sinh: ";
		getline(cin, ngaysinh);

	}
	virtual void Xuat()
	{}
	virtual bool Check() = 0;
	virtual string chucvu() = 0;
};
class GiangVien : public NhanVien
{
private:
	int sotiet;
	int sodetai;
public:
	void Nhap()
	{
		NhanVien::Nhap();
		cout << "So tiet giang day: ";
		cin >> sotiet;
		cout << "So de tai khoa luan: ";
		cin >> sodetai;
	}
	bool Check()
	{
		if (sotiet >= 300 && sodetai >= 5) return true;
		return false;
	}
	string chucvu()
	{
		return "Giang vien";
	}
	void Xuat()
	{
		if (Check()==true)
		{
			cout << hovaten << "  " << chucvu();
		}
	}
};
class Nghiencuuvien : public NhanVien
{
private:
	int sodetai1;
	int sobaibao;
public:
	void Nhap()
	{
		NhanVien::Nhap();
		cout << "So bai bao la tac gia: ";
		cin >> sobaibao;
		cout << "So de tai nghien cuu: ";
		cin >> sodetai1;
	}
	bool Check()
	{
		if (sodetai1 >= 1 && sobaibao >= 2) return true;
		return false;
	}
	string chucvu()
	{
		return "Nghien Cuu Vien";
	}
	void Xuat()
	{
		if (Check() == true)
		{   
			cout << hovaten << "  " << chucvu();
		}
	}
};
class Nhanvienvanphong : public NhanVien
{
private:
	int lopboiduong;
	int giolaodong;
public:
	void Nhap()
	{
		NhanVien::Nhap();
		cout << "So lop boi duong: ";
		cin >> lopboiduong;
		cout << "So gio lao dong: ";
		cin >> giolaodong;
	}
	bool Check()
	{
		if (lopboiduong >= 1 && giolaodong >= 20) return true;
		return false;
	}
	string chucvu()
	{
		return "Nhan vien van phong";
	}
	void Xuat()
	{
		if (Check() == true)
		{
			cout << hovaten << "  " << chucvu();
		}
	}
};
class QLNV
{
private:
	NhanVien** ds;
	int n;
public:
	friend  istream& operator >>(istream& in, QLNV& Ds)
	{
		cout << "Nhap so luong nhan vien: ";
		cin >> Ds.n;
		Ds.ds = new NhanVien * [Ds.n];
		cout << "Nhap thong tin cua cac thanh vien trong danh  sach" << endl;
		cout << "1.Giang vien" << endl;
		cout << "2.Nghien cuu vien" << endl;
		cout << "3.Nhan vien van phong" << endl;
		for (int i = 0; i < Ds.n; i++)
		{
			cout << "Nhap chuc vu: ";
			int flag;
			cin >> flag;
			cin.ignore();
			switch (flag)
			{
			case 1:
				Ds.ds[i] = new GiangVien;
				Ds.ds[i]->Nhap();
				break;
			case 2:
				Ds.ds[i] = new Nghiencuuvien;
				Ds.ds[i]->Nhap();
				break;
			case 3:
				Ds.ds[i] = new Nhanvienvanphong;
				Ds.ds[i]->Nhap();
				break;
			}
		}
		return in;
	}
	friend  ostream& operator <<(ostream& out, QLNV Ds)
	{
		cout << "Nhan vien du tieu chuan tien tien la : ";
		for (int i = 0; i < Ds.n; i++)
		{
			Ds.ds[i]->Xuat();
			cout << endl;
		}
		return out;
	}
};
int main()
{
	QLNV a; 
	cin >> a; 
	cout << a;
}
