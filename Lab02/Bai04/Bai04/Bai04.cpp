#include <iostream>
#include "mangmotchieu.h"
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	mangmotchieu A;
	A.nhap();
	cout << endl;
	A.xuat();
	cout << endl;
	A.x_Count();
	cout << endl;
	A.check_increase();
	cout << endl;
	A.odd_min();
	cout << endl;
	A.max_prime();
	cout << endl;
	system("pause");
	return 0;
}