//STACK.cpp
#include <iostream>
#include "STACK.h"
#include "linkedlist.h"
#include "element.h"
using namespace std;

STACK::STACK()
{
	this->nNum = 0;
	this->Linkedlist = new linkedlist();

}

STACK::~STACK()
{
}

void STACK::push(int x)
{
	element* p = new element(x);
	this->Linkedlist->InsertFirst(p);
}

int STACK::pop()
{
	if (this->Linkedlist->Gethead() == nullptr) {
		cout << "STACK RONG, KHONG LAY DUOC PHAN TU\n";
		return nullptr;
	}
	int p = this->Linkedlist->Gethead()->Getdata();
	this->Linkedlist->DeleteFirst();
	return p;
}

void STACK::printStack()
{
	this->Linkedlist->Travel();
	return;
}
