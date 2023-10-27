#include"PoKeMon.h"
void Pokemon::NhapPoKeMon() {
	cout << "Nhap ten: ";
	cin.ignore();
	getline(cin, Ten);
	cout << "Nhap he: ";
	fflush(stdin);
	getline(cin, He);
	cout << "Nhap mau: ";
	cin >> Mau;
	cout << "Nhap sat thuong gay ra: ";
	cin >> SatThuongGayRa;
}
void Pokemon::XuatPoKeMon() {
	cout << "Ten: " << Ten << endl;
	cout << "He: " << He << endl;
	cout << "Mau: " << Mau << endl;
	cout << "Sat thuong gay ra: " << SatThuongGayRa << endl;
}
void Pokemon::GhiDuLieuVaoFile(ofstream& a) {
	a << "\tKet qua nguoi thua cuoc\n";
	a << "Ten: " << Ten << endl;
	a << "He: " << He << endl;
	a << "Mau: " << Mau << endl;
	a << "Sat thuong gay ra: " << SatThuongGayRa << endl;
}
int Pokemon::operator>(Pokemon a) {
	int dem = 0;
	if (Mau > a.Mau) dem++;
	if (SatThuongGayRa > a.SatThuongGayRa) dem++;
	if (He == "nuoc" && a.He == "lua") dem++;
	else if (He == "lua" && a.He == "co") dem++;
	else if (He == "co" && a.He == "dat") dem++;
	else if (He == "dat" && a.He == "nuoc") dem++;
	else if (He == "co" && a.He == "nuoc") dem++;
	else if (He == "dat" && a.He == "lua") dem++;
	if (dem >= 2) return 1;
	else return 0;
}
int Pokemon::getMau() {
	return Mau;
}
int Pokemon::getSatThuongGayRa() {
	return SatThuongGayRa;
}
void Pokemon::setMau(int m) {
	Mau = Mau - m;
}
void Pokemon::setSatThuongGayRa(int stgr) {
	SatThuongGayRa = SatThuongGayRa - stgr;
}
string Pokemon::getHe() {
	return He;
}
//Cau a
void NhapDanhSachpokemon(Pokemon* pkm[], int& n) {
	cout << "Nhap so luong pokemon: ";
	cin >> n;
	for (int i = 0;i < n;i++) {
		pkm[i] = new Pokemon();
		cout << "\tNhap pokemon thu " << i + 1 << endl;
		pkm[i]->NhapPoKeMon();
	}
}
//Cau b
void Xuatpokemon(Pokemon* pkm[], int n) {
	cout << "===== THONG TIN DANH SACH POKEMON =====\n";
	for (int i = 0;i < n;i++) {
		cout << "\tPokemon thu " << i + 1 << endl;
		pkm[i]->XuatPoKeMon();
	}
}
//Cau c
void ThiDau2PoKeMon(Pokemon* pkm[], int n) {
	int vt1, vt2;
	cout << "Nhap vi tri pokemon 1: ";
	cin >> vt1;
	if (vt1 > n || vt1 < 1) cout << "Vi tri cua pokemon 1 khong hop le\n";
	else {
		cout << "Nhap vi tri pokemon 2: ";
		cin >> vt2;
		if (vt2 == vt1 || vt2 > n || vt2 < 1) cout << "Vi tri cua pokemon 2 khong hop le\n";
		else {
			int dem = 1;
			if (pkm[vt1 - 1] > pkm[vt2 - 1]) {
				while (1) {
					if (pkm[vt2 - 1]->getHe() == "nuoc" && pkm[vt1 - 1]->getHe() == "lua") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.2);
					else if (pkm[vt2 - 1]->getHe() == "lua" && pkm[vt1 - 1]->getHe() == "co") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.25);
					else if (pkm[vt2 - 1]->getHe() == "co" && pkm[vt1 - 1]->getHe() == "dat") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.15);
					else if (pkm[vt2 - 1]->getHe() == "dat" && pkm[vt1 - 1]->getHe() == "nuoc") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.3);
					else if (pkm[vt2 - 1]->getHe() == "co" && pkm[vt1 - 1]->getHe() == "nuoc") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.1);
					else if (pkm[vt2 - 1]->getHe() == "dat" && pkm[vt1 - 1]->getHe() == "lua") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.35);
					else pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa());
					if (pkm[vt1 - 1]->getMau() <= 0) {
						ofstream FileOut;
						FileOut.open("WINNER.OUT");
						pkm[vt1 - 1]->GhiDuLieuVaoFile(FileOut);
						FileOut.close();
						cout << "\tLuot danh thu " << dem++ << endl;
						cout << "Mau cua pokemon vi tri thu " << vt1 << " la: " << pkm[vt1 - 1]->getMau() << endl;
						cout << "Mau cua pokemon vi tri thu " << vt2 << " la: " << pkm[vt2 - 1]->getMau() << endl;
						cout << "Pokemon vi tri " << vt1 << " da bi thua va ghi vao thong vao file WINNER.OUT thanh cong\n";
						break;
					}
					if (pkm[vt1 - 1]->getHe() == "nuoc" && pkm[vt2 - 1]->getHe() == "lua") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.2);
					else if (pkm[vt1 - 1]->getHe() == "lua" && pkm[vt2 - 1]->getHe() == "co") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.25);
					else if (pkm[vt1 - 1]->getHe() == "co" && pkm[vt2 - 1]->getHe() == "dat") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.15);
					else if (pkm[vt1 - 1]->getHe() == "dat" && pkm[vt2 - 1]->getHe() == "nuoc") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.3);
					else if (pkm[vt1 - 1]->getHe() == "co" && pkm[vt2 - 1]->getHe() == "nuoc") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.1);
					else if (pkm[vt1 - 1]->getHe() == "dat" && pkm[vt2 - 1]->getHe() == "lua") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.35);
					else pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa());
					if (pkm[vt2 - 1]->getMau() <= 0) {
						ofstream FileOut;
						FileOut.open("WINNER.OUT");
						pkm[vt2 - 1]->GhiDuLieuVaoFile(FileOut);
						FileOut.close();
						cout << "\tLuot danh thu " << dem++ << endl;
						cout << "Mau cua pokemon vi tri thu " << vt1 << " la: " << pkm[vt1 - 1]->getMau() << endl;
						cout << "Mau cua pokemon vi tri thu " << vt2 << " la: " << pkm[vt2 - 1]->getMau() << endl;
						cout << "Pokemon vi tri " << vt2 << " da bi thua va ghi vao thong vao file WINNER.OUT thanh cong\n";
						break;
					}
					cout << "\tLuot danh thu " << dem++ << endl;
					cout << "Mau cua pokemon vi tri thu " << vt1 << " la: " << pkm[vt1 - 1]->getMau() << endl;
					cout << "Mau cua pokemon vi tri thu " << vt2 << " la: " << pkm[vt2 - 1]->getMau() << endl;
				}
			}
			else {
				while (1) {
					if (pkm[vt1 - 1]->getHe() == "nuoc" && pkm[vt2 - 1]->getHe() == "lua") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.2);
					else if (pkm[vt1 - 1]->getHe() == "lua" && pkm[vt2 - 1]->getHe() == "co") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.25);
					else if (pkm[vt1 - 1]->getHe() == "co" && pkm[vt2 - 1]->getHe() == "dat") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.15);
					else if (pkm[vt1 - 1]->getHe() == "dat" && pkm[vt2 - 1]->getHe() == "nuoc") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.3);
					else if (pkm[vt1 - 1]->getHe() == "co" && pkm[vt2 - 1]->getHe() == "nuoc") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.1);
					else if (pkm[vt1 - 1]->getHe() == "dat" && pkm[vt2 - 1]->getHe() == "lua") pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa() + pkm[vt1 - 1]->getSatThuongGayRa() * 0.35);
					else pkm[vt2 - 1]->setMau(pkm[vt1 - 1]->getSatThuongGayRa());
					if (pkm[vt2 - 1]->getMau() <= 0) {
						ofstream FileOut;
						FileOut.open("WINNER.OUT");
						pkm[vt2 - 1]->GhiDuLieuVaoFile(FileOut);
						FileOut.close();
						cout << "\tLuot danh thu " << dem++ << endl;
						cout << "Mau cua pokemon vi tri thu " << vt1 << " la: " << pkm[vt1 - 1]->getMau() << endl;
						cout << "Mau cua pokemon vi tri thu " << vt2 << " la: " << pkm[vt2 - 1]->getMau() << endl;
						cout << "Pokemon vi tri " << vt2 << " da bi thua va ghi vao thong vao file WINNER.OUT thanh cong\n";
						break;
					}
					if (pkm[vt2 - 1]->getHe() == "nuoc" && pkm[vt1 - 1]->getHe() == "lua") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.2);
					else if (pkm[vt2 - 1]->getHe() == "lua" && pkm[vt1 - 1]->getHe() == "co") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.25);
					else if (pkm[vt2 - 1]->getHe() == "co" && pkm[vt1 - 1]->getHe() == "dat") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.15);
					else if (pkm[vt2 - 1]->getHe() == "dat" && pkm[vt1 - 1]->getHe() == "nuoc") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.3);
					else if (pkm[vt2 - 1]->getHe() == "co" && pkm[vt1 - 1]->getHe() == "nuoc") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.1);
					else if (pkm[vt2 - 1]->getHe() == "dat" && pkm[vt1 - 1]->getHe() == "lua") pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa() + pkm[vt2 - 1]->getSatThuongGayRa() * 0.35);
					else pkm[vt1 - 1]->setMau(pkm[vt2 - 1]->getSatThuongGayRa());
					if (pkm[vt1 - 1]->getMau() <= 0) {
						ofstream FileOut;
						FileOut.open("WINNER.OUT");
						pkm[vt1 - 1]->GhiDuLieuVaoFile(FileOut);
						FileOut.close();
						cout << "\tLuot danh thu " << dem++ << endl;
						cout << "Mau cua pokemon vi tri thu " << vt1 << " la: " << pkm[vt1 - 1]->getMau() << endl;
						cout << "Mau cua pokemon vi tri thu " << vt2 << " la: " << pkm[vt2 - 1]->getMau() << endl;
						cout << "Pokemon vi tri " << vt1 << " da bi thua va ghi vao thong vao file WINNER.OUT thanh cong\n";
						break;
					}
					cout << "\tLuot danh thu " << dem++ << endl;
					cout << "Mau cua pokemon vi tri thu " << vt1 << " la: " << pkm[vt1 - 1]->getMau() << endl;
					cout << "Mau cua pokemon vi tri thu " << vt2 << " la: " << pkm[vt2 - 1]->getMau() << endl;
				}
			}
		}
	}
}