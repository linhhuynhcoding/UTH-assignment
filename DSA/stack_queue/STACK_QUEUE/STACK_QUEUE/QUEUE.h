//QUEUE.h
#pragma once
#include "linkedlist.h"
using namespace std;
class QUEUE
{
private: 
    int nNum;
    linkedlist* Linkedlist;
public:
    QUEUE();
    virtual ~QUEUE();
    void push(int);
    int pop();

    void printQueue();
};

