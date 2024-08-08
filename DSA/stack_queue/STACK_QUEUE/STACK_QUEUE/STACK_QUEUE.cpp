// STACK_QUEUE.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdio.h>
#include <vector>
#include "element.h"
#include "linkedlist.h"
#include "STACK.h"
#include "QUEUE.h"

using namespace std;

void toatau1() {
    int n;
    cout << "Nhap so luong toa tau: ";
    cin >> n;
    vector <int> a(n);
    STACK* A = new STACK();
    STACK* B = new STACK();
    vector <string> C;
    cout << "Nhap thu tu toa tau: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) A->push(i);
    int index = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
        int tmp = A->pop();
        if (tmp == NULL || a[i] < tmp) {

            tmp = B->pop();
            if (tmp == NULL || tmp != a[i]) {
                cout << "KHONG THE DI CHUYEN\n";
                return;
            }
            C.push_back("B-->C");
            continue;
        }
        else {
            while (tmp != a[i]) {
                B->push(tmp);
                C.push_back("A-->B");
                tmp = A->pop();
            }
            if (tmp == NULL) {
                cout << "KHONG THE DI CHUYEN\n";
                return;
            }
            else {
                C.push_back("A-->C");
                continue;                
            }
        }
    }

    for (int i = 0; i < C.size(); i++) {
        cout << i + 1 << ").\t" << C[i] << "\n";
    }
}

void Mecung() {
    int a[3][3] = {
        {1, 1, 0},
        {0, 0, 1},
        {0, 1, 1}
    };
    int x1, x2, y1, y2;
    x1 = y1 = 0;
    x2 = y2 = 2;
    if (a[x2][y2] == 0) {
        cout << "KHONG THE DI DEN!\n";
        return;
    }

    QUEUE* qx = new QUEUE();
    QUEUE* qy = new QUEUE();
    bool flag = false;

    while (a[x1][y1] != 0 && flag == false) {
        cout << x1 << " " << y1 << " " << a[x1][y1] << "\n";
        if (x1 == x2 && y1 == y2) {
            flag = true;
            break;
        }
        a[x1][y1] = 0;

        if (x1 + 1 < 3) {
            if (a[x1 + 1][y1] != 0) {
                qx->push(x1 + 1);
                qy->push(y1);
            }
        }
        if (x1 - 1 >= 0) {
            if (a[x1 - 1][y1] != 0) {
                qx->push(x1 - 1);
                qy->push(y1);
            }
        }
        if (y1 + 1 < 3) {
            if (a[x1][y1 + 1] != 0) {
                qx->push(x1);
                qy->push(y1 + 1);
            }
        }
        if (y1 - 1 >= 0) {
            if (a[x1][y1 - 1] != 0) {
                qx->push(x1);
                qy->push(y1 - 1);
            }
        }
        x1 = qx->pop();
        y1 = qy->pop();
    }

    if (flag == true) {
        cout << "CO THE DI DEN!\n";
        return;
    }
    else {
        cout << "KHONG THE DI DEN!\n";
        return;
    }
}

void DemicalToBinary(int x) {
    STACK* b = new STACK();
    while (x != 0) {
        b->push(x%2);
        x /= 2;
    }
    cout << "Binary : ";
    b->printStack();
    return;
}

int main()
{
    cout << "\n-----STACK----\n";
    STACK* s = new STACK();
    s->push(7);
    s->push(10);
    s->push(18);

    s->printStack();
    int tmp;
    cout << "\n";
    while (tmp = s->pop()) {
        cout << tmp << " ";
    }
    

    cout << "\n-----QUEUE----\n";
    QUEUE* q = new QUEUE();
    q->push(5);
    q->push(7);
    q->push(6);
    q->push(1);
    q->printQueue();
    cout << "\n";
    while (tmp = q->pop()) {
        cout << tmp << " ";
    }

    cout << "\n-----DEMICALTOBINARY----\n";
    DemicalToBinary(5);

    cout << "\n-----MECUNG----\n";
    Mecung();

    cout << "\n-----TOATAU1----\n";
    toatau1();
}

