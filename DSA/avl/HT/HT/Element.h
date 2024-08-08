#pragma once
#include "SinhVien.h"
class Element
{
private:
    SinhVien data;
    Element *pointer;
public:
    Element() {
        this->data = SinhVien("");
        this->pointer = nullptr;
    }
    SinhVien Getdata() { return this->data; }
    void Setdata(SinhVien val) { this->data = val; }
    Element *Getpointer() { return pointer; }
    void Setpointer(Element *val) { pointer = val; }
    friend ofstream operator << (ostream ofs, Element a) {
        ofs << a.data;
        return ofs;
    }
};