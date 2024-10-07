//QUEUE.cpp
#include "QUEUE.h"
#include <iostream>

QUEUE::QUEUE()
{
	this->nNum = 0;
	this->Linkedlist = new linkedlist();
}

QUEUE::~QUEUE()
{
}

void QUEUE::push(int x)
{
	element* p = new element(x);
	this->Linkedlist->InsertFirst(p);
}

int QUEUE::pop()
{
	if (this->Linkedlist->Gethead() == nullptr) {
		cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU\n";
		return nullptr;
	}
	int p = this->Linkedlist->Gettail()->Getdata();
	this->Linkedlist->DeleteTail();
	return p;
}

void QUEUE::printQueue()
{
	this->Linkedlist->Travel();
	return;
}
