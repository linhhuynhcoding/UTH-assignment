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

  string linkedlist::toString()
  {
      string out = "";
      element* p = this->Gethead();
      while (p != nullptr ) {
          out += p->Getdata().toString();
          p = p->Getpointer();
          if (p != nullptr) out += "->";
      }
      return out;
  }



