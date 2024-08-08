#pragma once
#include "element.h"

class LinkedList
{
private:
    Element *head;
    Element *tail;
    int nNum;

public:
    LinkedList();
    Element *Gethead() { return head; }
    void Sethead(Element *val) { head = val; }
    Element *Gettail() { return tail; }
    void InsertFirst(Element *);
    void InsertTail(Element *);
    bool DeleteFirst();
    int getSize();
    void print() {
        Element * p = head;
        while (p != nullptr)
        {
            cout << *p;
        }
        
    }
};