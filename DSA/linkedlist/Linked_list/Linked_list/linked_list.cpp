/// File: linkedlist.cpp

#include "linkedlist.h"
#include <iostream>
#include <math.h>
using namespace std;
linkedlist::linkedlist()
{
    //ctor
    this->head=nullptr;
    this->tail=nullptr;
    this->nNum=0;
}

linkedlist::~linkedlist()
{
    //dtor
}
void linkedlist::InsertFirst(element* e){
    //if (this->ValueDuplicate(e->Getdata()) > 0) return;
      if(this->head==nullptr)
        this->head=this->tail=e;
        else{
            e->Setpointer(this->head);
            this->head=e;
        }
       this->nNum++;

}
 void linkedlist::InsertTail(element*e){
     //if (this->ValueDuplicate(e->Getdata()) > 0) return;
     if(this->head==nullptr)
        this->head=this->tail=e;
        else{
            this->tail->Setpointer(e);// step 1
            this->tail=e;    // step 2
        }
     this->nNum++;
 }
void linkedlist::Travel(){
     element* p=this->head;
     while(p!=nullptr){
        cout<<p->Getdata()<<" ";
        p=p->Getpointer();
     }
}
  bool linkedlist::DeleteFirst(){
      if(this->head==nullptr) return false;
      else{
      element*p=this->head;
      this->head=this->head->Getpointer();
      delete p;
      return true;
      }
  }

  bool linkedlist::DeleteTail()
  {
      element* p = this->head;
      if (p == this->tail) {
          this->head = nullptr;
          return true;
      }
      while (p->Getpointer() != this->tail) {
          p = p->Getpointer();
      }
      this->tail = p;
      this->tail->Setpointer(nullptr);
      return true;
  }

  void linkedlist::RemoveAll() {
      element* p = this->head;
      while (p != nullptr) {
          element* tmp = p->Getpointer();
          this->DeleteFirst();
          p = tmp;
      }
  }

  int linkedlist::SumList()
  {
      int sum = 0;
      element* p = this->head;
      while (p != nullptr) {
          sum += p->Getdata();
          p = p->Getpointer();
      }
      return sum;
  }

  int linkedlist::MaxList()
  {
      element* p = this->head;
      int _max = p->Getdata();
      while (p != nullptr) {
          _max = max(p->Getdata(), _max);
          p = p->Getpointer();
      }
      return _max;
  }

  int linkedlist::CountPrime()
  {
        
        element* p = this->head;
        int cnt = 0;
        while (p != nullptr) {
            int d = p->Getdata();
            int check = false;
            if (d < 2) check = false;
            else if (d == 2) check = true;
            else {
                int flag = 0;
                check = true;
                for (int i = 2; i < sqrt(d); i++) {
                    if (d % i == 0) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) cnt++;
            p = p->Getpointer();
        }
        return cnt;
  }

  void linkedlist::InsertAfterP(element* p)
  {
      int temp_data;
      cout << "Nhap gia tri muon them :"; cin >> temp_data;
      element* insertE = new element(temp_data);

      if (p == this->head) {
          return this->InsertFirst(insertE);
      }
      else if (p == this->tail) {
          return this->InsertTail(insertE);
      }
      else {
          element* cur = this->head->Getpointer();
          while (cur != nullptr || cur != p) {
              cur = cur->Getpointer();
          }
          if (cur == nullptr) {
              return;
          }
          insertE->Setpointer(p->Getpointer());
          p->Setpointer(insertE);
          return;
      }
  }

  void linkedlist::DeleteP(element* p)
  {
      if (p == this->head) {
          this->DeleteFirst();
          return;
      }
      else {
          element* after = this->head;
      
          while (after->Getpointer() != p) {
              after = after->Getpointer();
          }
          element* cur = after->Getpointer();
          after->Setpointer(cur->Getpointer());
          delete cur;
          return;
      }
  }

  int linkedlist::ValueDuplicate(int x)
  {
      int cnt = 0;
      element* p = this->head;
      while (p != nullptr) {
          if (p->Getdata() == x) {
              cnt++;
          };
          p = p->Getpointer();
      }
      return cnt;
  }

  void linkedlist::SplitLinkedList(linkedlist* listA, linkedlist* listB, int x)
  { 
      element* p = this->head;
      while (p != nullptr) {
          if (p->Getdata() > x) {
              listA->InsertTail(p);
          }
          else if (p->Getdata() < x) {
              listB->InsertTail(p);
          }
          p = p->Getpointer();
      }
      return;
  }

