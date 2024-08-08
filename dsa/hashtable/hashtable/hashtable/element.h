#include <iostream>
#include "MyData.h"

using namespace std;

class element
{
private:
    MyData data;
    element* pointer;

public:
    element();
    element(MyData);
    virtual ~element();

    MyData Getdata() { return data; }
    void Setdata(MyData val) { data = val; }
    element* Getpointer() { return pointer; }
    void Setpointer(element* val) { pointer = val; }


    protected:

};


