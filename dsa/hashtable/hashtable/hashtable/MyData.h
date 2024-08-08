#include "KeyData.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
#pragma once
class MyData
{
private :
	string hoten, email, mssv;

public:
	MyData();
	MyData(string, string, string);
	bool operator== (KeyData b);
	bool operator!= (KeyData b);

	string toString();

	friend ostream& operator<<(ostream& out, MyData mydata) {
		out << mydata.toString();
		return out;
	};
};

