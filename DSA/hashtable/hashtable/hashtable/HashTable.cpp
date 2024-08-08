//HashTable.cpp
#include "HashTable.h"

HashTable::HashTable(int k) {
	this->NumOfBuckets = k;
	//this->value = new linkedlist[k];
	this->value.assign(k, nullptr);
}

int HashTable::getHashKey(KeyData keydata) {
	return keydata.Hashing() % NumOfBuckets;
}
MyData* HashTable::getValue(KeyData keydata) {
	int hashkey = this->getHashKey(keydata);
	return this->value[hashkey];
	//linkedlist* cur = this->value + hashkey;
	/*element* p = cur->Gethead();
	while (p != nullptr || p->Getdata() != keydata) {
		p = p->Getpointer();
	}
	return p->Getdata();*/
}

bool HashTable::Insert(KeyData keydata, MyData* mydata)
{
	int hashkey = this->getHashKey(keydata);
	int i = hashkey;
	while (this->value[i] != nullptr) {
		i = (i + i*i) % NumOfBuckets;
		if (i >= this->NumOfBuckets)
			return false;
	}
	if (this->value[i] == nullptr) {
		this->value[i] = mydata;
	}
	//value[hashkey].push_back(mydata);
	/*element* n = new element(mydata);
	linkedlist* cur = (this->value + hashkey);
	cur->InsertTail(n);*/
	return true;
}

void HashTable::toScreen() {
	cout << setw(15) << left << "Buckets";
	cout << left << "Value";
	cout << "\n";
	for (int i = 0; i < NumOfBuckets; i++) {
		cout << setw(15) << left << i;
		//string s = (this->value + i)->toString();
		string s = "";
		if (value[i] != nullptr) {
			cout << *value[i];
			cout << left << s;
		}
		cout << "\n";

	}
};

