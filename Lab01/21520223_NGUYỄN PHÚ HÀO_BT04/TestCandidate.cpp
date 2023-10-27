#include "Candidate.h"
#include "TestCandidate.h"
#include <iostream>

using namespace std;

void TestCandidate::Input()
{
	cout << "Nhap vao so luong thi sinh: ";
	cin >> n;
	list = new Candidate[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Thi sinh " << i + 1 << ": \n";
		list[i].Input();
	}
}
void TestCandidate::Output()
{
	for (int i = 0; i < n; i++)
		list[i].Output();
}
void TestCandidate::Dieukien()
{
	cout << "Cac hoc sinh co tong diem lon hon 15: \n\n";
	for (int i = 0; i < n; i++)
		if (list[i].Check() == 1)
			list[i].Output();
}