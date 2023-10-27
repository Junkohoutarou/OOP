#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Pokemon {
private:
	string Ten, He;
	int Mau, SatThuongGayRa;
public:
	void NhapPoKeMon();
	void XuatPoKeMon();
	void GhiDuLieuVaoFile(ofstream& a);
	int operator >(Pokemon a);
	int getMau();
	int getSatThuongGayRa();
	void setMau(int m);
	void setSatThuongGayRa(int stgr);
	string getHe();
};
//Cau a
void NhapDanhSachpokemon(Pokemon* pkm[], int& n);
//Cau b
void Xuatpokemon(Pokemon* pkm[], int n);
//Cau c
void ThiDau2PoKeMon(Pokemon* pkm[], int n);