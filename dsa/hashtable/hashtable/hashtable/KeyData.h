
#include <iostream>
#include <string>
using namespace std;
#pragma once
class KeyData
{
private :
	string value;
public :
	KeyData(string);
	int Hashing() {
		int sumofc = 0;
		for (char c : value) {
			sumofc += int(c);
		}
		return sumofc;
	}
	string getValue() { return value; }
};

