#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Hocsinh
{
public:
	string hoten;
	int maso;
	string sdt;
	float dtb;
	Hocsinh();
	Hocsinh(string, int, string, float);
	void Nhap();
	void Xuat();
	~Hocsinh();
};
class Lophoc
{
private:
	vector<Hocsinh> danhsach;
public:
	Lophoc();
	Lophoc(vector<Hocsinh>);
	int sophantu();
	bool kttrunglap(Hocsinh);
	void addhocsinh(Hocsinh);
	void deletehocsinh(Hocsinh);
	void printallhocsinh();
	void xuathocsinhdtbtren8();
	~Lophoc();
};