//DaThuc.h

#include "PhanTu.h"
#pragma once
class DaThuc
{
private:
	PhanTu* head;
	PhanTu* tail;
	int nNum;

public:
    DaThuc();
    PhanTu* Gethead() { return head; }
    PhanTu* Gettail() { return tail; }
    void Sethead(PhanTu*);
    void Settail(PhanTu*);
    void Insert(PhanTu*);
    void Delete(PhanTu*);

    void In();
    void Rutgon();
    DaThuc* Cong(DaThuc* dt2);
    DaThuc* Nhan(DaThuc* dt2);
};

