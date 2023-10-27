#pragma once
#include "Candidate.h"

using namespace std;

class TestCandidate
{
private:
	int n;
	Candidate* list;
public:
	void Input();
	void Output();
	void Dieukien();
};