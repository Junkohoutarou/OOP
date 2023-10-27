#define MAIN_SAVITCH_SEQUENCE_H
#include"PoKeMon.h"
int main() {
	Pokemon* pkm[200];
	int n = 0;
	NhapDanhSachpokemon(pkm, n);
	Xuatpokemon(pkm, n);
	ThiDau2PoKeMon(pkm, n);
	return 0;
}