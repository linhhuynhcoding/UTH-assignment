#pragma once
#include "Bieuthuc.h"
#include <iostream>
using namespace std;
class BieuthucPT : public Bieuthuc
{
private:
    Bieuthuc *bt1;
    Bieuthuc *bt2;
    //..Bổ sung thêm dữ liệu để lưu trữ được (a#b) # (c#d)
public:
    BieuthucPT(int level); //overide để sinh ngẫu nhiên được dạng biểu thức mới, quy luật sinh như sinh lớp Bieuthuc
    friend ostream& operator<<(ostream& out, BieuthucPT bt); //overide để xuất dạng biểu thức mới
};
