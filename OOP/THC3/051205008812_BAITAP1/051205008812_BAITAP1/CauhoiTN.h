#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma once
class CauhoiTN
{
private:
	string question ;
	string answerA, answerB;
	string correctAnswer;
public:
	void nhap();
	bool docfile(ifstream& f);
	void ghifile(ofstream& f);
	bool kiemtra();
	void xuat();

	friend bool giongnhau(CauhoiTN, CauhoiTN);
};

