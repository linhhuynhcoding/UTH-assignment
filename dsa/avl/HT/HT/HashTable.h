#include "LinkedList.h"
#include <iostream>
class HashTable
{
private:
    LinkedList *a;
    int size;
    int getHash(string name) {
        int res = 0;
        for (char x : name)
            res += x;
        return res % this->size;
    }
public:
    HashTable(int size) {
        this-> size = size;
        a = new LinkedList[size];
    }
    void insert(SinhVien sv) {
        int hashValue = getHash(sv.fullName);
        Element * e = new Element();
        a[hashValue].InsertTail(e);
    }
};
