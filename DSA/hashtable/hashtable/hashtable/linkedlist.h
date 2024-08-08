#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "element.h"

class linkedlist
{
     private:
        element* head;
        element* tail;
        int nNum;
    public:
        linkedlist();
        virtual ~linkedlist();
        element* Gethead() { return head; }
        void Sethead(element* val) { head = val; }
        element* Gettail() { return tail; }
        void Settail(element* val) { tail = val; }
        void InsertFirst(element*);
        void InsertTail(element*);
        bool DeleteFirst();
        bool DeleteTail();
        void Travel();

        void RemoveAll();
        void DeleteP(element*);

        string toString();

    protected:


};

class LINKEDLIST
{
};

#endif // LINKEDLIST_H
