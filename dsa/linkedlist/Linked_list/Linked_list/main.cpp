///File: main.cpp

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    linkedlist *list_=new linkedlist();
    element *e;
    e=new element(9);
    list_->InsertTail(e);
    e=new element(10);
     list_->InsertTail(e);
    e=new element(8);
     list_->InsertTail(e);
    list_->Travel();
    cout<<"\n";
    list_->DeleteP(list_->Gethead()->Getpointer());
     list_->Travel();
    return 0;
}
