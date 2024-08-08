//DaThuc.cpp
#include "DaThuc.h"
#include <iostream>
using namespace std;

DaThuc::DaThuc()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

void DaThuc::Sethead(PhanTu* _head)
{
    this->head = _head;
    return;
}

void DaThuc::Settail(PhanTu* _tail)
{
    this->tail = _tail;
    return;
}

void DaThuc::Insert(PhanTu* _next)
{
    if (this->head == nullptr) {
        this->head = this->tail = _next;
        return;
    }
    this->tail->GanNext(_next);
    this->tail = _next;
    this->tail->GanNext(nullptr);
}

void DaThuc::Delete(PhanTu* target)
{
    if (this->head == target) {
        this->head = this->head->LayNext();
        return;
    }

    PhanTu* p = this->head;
    while (p != nullptr)
    {
        if (p->LayNext() == target) {
            p->GanNext(target->LayNext());
            return;
        }
        p = p->LayNext();
    }
    return;
}

void DaThuc::In()
{
    PhanTu* p = this->head;
    while (p != nullptr)
    {
        cout << p->LayCoso() << "*X^" << p->LaySomu();
        p = p->LayNext();
        if (p != nullptr) cout << " + ";
    }
    return;
}

void DaThuc::Rutgon()
{
    PhanTu* p = this->head;
    while (p != nullptr)
    {
        PhanTu* p2 = p->LayNext();
        while (p2 != nullptr)
        {
            PhanTu* tmp = p2->LayNext();

            if (p2->LaySomu() == p->LaySomu()) {
                p->GanCoso(p->LayCoso() + p2->LayCoso());
                this->Delete(p2);
            }
            p2 = tmp;
        }
        p = p->LayNext();
    }
    return;
}

DaThuc* DaThuc::Cong(DaThuc* dt2)
{
    DaThuc* tong = new DaThuc();
    PhanTu* p1 = this->head;
    while (p1 != nullptr)
    {
        tong->Insert(p1);
        p1 = p1->LayNext();
    }
    PhanTu* p2 = dt2->head;
    while (p2 != nullptr)
    {
        tong->Insert(p2);
        p2 = p2->LayNext();
    }
    tong->Rutgon();
    return tong;
}

DaThuc* DaThuc::Nhan(DaThuc* dt2)
{
    DaThuc* tich = new DaThuc();
    PhanTu* p1 = this->head;
    while (p1 != nullptr)
    {
        PhanTu* p2 = this->head;

        while (p2 != nullptr) {
            if (p2->LaySomu() == p1->LaySomu()) {
                PhanTu* p3 = new PhanTu();
                p3->GanCoso(p1->LayCoso() * p2->LayCoso());
                p3->GanSomu(p1->LaySomu() * p2->LaySomu());

                tich->Insert(p3);
            }
            p2 = p2->LayNext();
        }
    }
    tich->Rutgon();
    return tich;
}
