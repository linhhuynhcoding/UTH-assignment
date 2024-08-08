#include "linkedlist.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
    // ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

int LinkedList::getSize()
{
    return this->nNum;
}

void LinkedList::InsertFirst(Element *e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        e->Setpointer(this->head);
        this->head = e;
    }
    this->nNum++;
}

void LinkedList::InsertTail(Element *e)
{
    this->nNum++;
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        this->tail->Setpointer(e);
        this->tail = e;
    }
}

bool LinkedList::DeleteFirst()
{
    if (this->head == nullptr)
        return false;
    else
    {
        Element *p = this->head;
        this->head = this->head->Getpointer();
        delete p;
        this->nNum--;
        return true;
    }
}