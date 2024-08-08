//HashTable.h

#include "linkedlist.h"
#include "KeyData.h"
#include <iomanip>
#include <vector>


#pragma once
class HashTable
{
private:
	int NumOfBuckets = 0;
	//linkedlist* value;
	vector <MyData*> value;
	int getHashKey(KeyData) ;
public:
	HashTable(int) ;
	MyData* getValue(KeyData) ;
	bool Insert(KeyData, MyData*);

	void toScreen();
};

