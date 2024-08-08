//STACK.h
#pragma once
#include "linkedlist.h"
using namespace std;

class STACK
{
private: int nNum;
       linkedlist* Linkedlist;
public:
    STACK();
    virtual ~STACK();
    void push(int);
    int pop();

    void printStack();

};

