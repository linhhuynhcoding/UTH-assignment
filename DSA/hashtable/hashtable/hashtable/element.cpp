/// File: element.cpp
#include "element.h"

element::element()
{
    //ctor
    this->data;
    this->pointer=nullptr;
}

element::element(MyData val)
{
    //ctor
    this->data = val;
    this->pointer = nullptr;
}


element::~element()
{
    //dtor
}
