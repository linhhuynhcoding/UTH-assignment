#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
	HashTable* ht = new HashTable(10);
	
	string dssv[][3] = {
		{"Huynh Vu Nhat Linh", "linh@mail.com", "1234"},
		{"Nguyen Dinh Phuc", "phuc@mail.com", "234"},
		{"Nguyen Dinh Phuc", "phuc2@mail.com", "567"},
		{"Phan Duc Tai", "tai@mail.com", "999"},
		{"Tran Phat Tai", "ptai@mail.com", "919"},
		{ "Phan Duc Tai", "tai2@mail.com", "111" }
	};
	for (auto i : dssv) {
		MyData* d = new MyData(i[0], i[1], i[2]);
		KeyData k(i[0]);
		ht->Insert(k, d);
	}

	ht->toScreen();
}