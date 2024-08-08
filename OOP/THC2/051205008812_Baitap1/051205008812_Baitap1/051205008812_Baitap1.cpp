// 051205008812_Baitap1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	fstream f;
	f.open("data.txt");
	int cnt = 0;
	string line;
	string res;
	while (getline(f, line)) {
		cnt++;
		int index = 0;
		if (line[index] == ' ') {
			index++;
		}
		if (line[index] == '-')
			res += line.substr(index, line.length() - index) + "\n\r";
	}

	cout << "Tong so dong la : " << cnt << "\n";
	cout << "Cac dong bat dau '-' la : \n";
	cout << res;
}

