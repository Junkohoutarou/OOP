#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

const int N = 100000;

using namespace std;

class mangmotchieu {
private:
	int n;
	int a[N];
public:
	mangmotchieu();
	mangmotchieu(int n, int a[N]);
	void nhap();
	void xuat();
	void x_Count(); //Count all of value in array with the same Value X
	void check_increase(); //Check strictly increasing sequence
	void odd_min(); // Find an odd min integer in array
	void max_prime(); // Find a maximum prime integer in array
	~mangmotchieu();
};