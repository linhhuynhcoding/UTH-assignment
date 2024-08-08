#include <iostream>
#include <fstream>
#include <string>
#include "CauhoiTN.h"
using namespace std;

void CauhoiTN::nhap()
{
	string _question;
	string _answerA, _answerB;
	string _correctAnswer;
	cout << "Nhap cau hoi : ";
	getline(cin, _question);
	cout << "Nhap cau tra loi A : ";
	getline(cin, _answerA);
	cout << "Nhap cau tra loi B : ";
	getline(cin, _answerB);
	cout << "Nhap dap an : ";
	getline(cin, _correctAnswer);
	question = _question;
	answerA = _answerA;
	answerB = _answerB;
	correctAnswer = _correctAnswer;
}

void CauhoiTN::docfile(ifstream& f)
{
	// format : CAUHOI|CAUTRALOIA|CAUTRALOIB|DAPAN
	string raw_data;
	getline(f, raw_data);
	question = raw_data.substr(0, raw_data.find("|"));
	raw_data.erase(0, raw_data.find("|") + 1);

	answerA = raw_data.substr(0, raw_data.find("|"));
	raw_data.erase(0, raw_data.find("|") + 1);

	answerB = raw_data.substr(0, raw_data.find("|"));
	raw_data.erase(0, raw_data.find("|") + 1);

	correctAnswer = raw_data.substr(0, 1);
}

void CauhoiTN::ghifile(ofstream& f)
{
	// format : CAUHOI|CAUTRALOIA|CAUTRALOIB|DAPAN
	string raw_data = question + "|" + answerA + "|" + answerB + "|" + correctAnswer;
	f << raw_data << "\n";
}

void CauhoiTN::kiemtra()
{
	string userAnswer;
	cout << "Cau hoi : " << question << "\n";
	cout << "Cau tra loi A : " << answerA << "\n";
	cout << "Cau tra loi B : " << answerB << "\n";
	do {
		cout << "Cau tra loi cua ban la? (A/B) : ";
		cin >> userAnswer;
	} while (userAnswer != "A" && userAnswer != "B");

	if (userAnswer == correctAnswer) {
		cout << "Chinh xac. Dap an la " << correctAnswer << "\n";
	}
	else {
		cout << "Chua chinh xac. Dap an la " << correctAnswer << "\n";
	}
}

void CauhoiTN::xuat()
{
	cout << "Cau hoi : " << question << "\n";
	cout << "Cau tra loi A : " << answerA << "\n";
	cout << "Cau tra loi B : " << answerB << "\n";
	cout << "Dap an : " << correctAnswer << "\n";
}


