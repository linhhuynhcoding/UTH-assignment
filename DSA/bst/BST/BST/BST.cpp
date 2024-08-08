//BST.cpp

#include "BST.h"
#include "NODE.h"
#include <iostream>
#include <queue>

using namespace std;
BST::BST()
{
    //ctor
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
}
bool BST::InsertNode(Node* n) {
    Node* p = this->root;
    Node* T = new Node();

    if (this->search_x(n->Getkey()) != nullptr) {
        this->search_x(n->Getkey())->Upfre();
        return true;
    }

    if (root == nullptr)
    {
        this->root = n;
        return true;
    }
    while (p != nullptr) {
        T = p;

        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else
            if (p->Getkey() < n->Getkey())
                p = p->Getright();
            else
                if (p->Getkey() == n->Getkey())
                    return false;
    }

    if (T->Getkey() > n->Getkey()) {
         T->Setleft(n);
    }
    else T->Setright(n);

    n->Setparent(T);
    return true;

}
bool BST::InsertNodeRe(Node* root, Node* p) {
    if (root == nullptr) {
        root = p;
        return true;
    }
    if (root->Getkey() == p->Getkey())
        return false;
    else if (root->Getkey() > p->Getkey())
        return InsertNodeRe(root->Getleft(), p);
    else return InsertNodeRe(root->Getright(), p);
}

void BST::NLR(Node* r) {
    if (r != nullptr) {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
void BST::LNR(Node* r) {
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << " : " << r->Getfre() << "\n";
        LNR(r->Getright());
    }
}
void BST::LRN(Node* r) {
    if (r != nullptr) {
        LRN(r->Getleft());
        LRN(r->Getright());
        cout << r->Getkey() << "\n";
    }
}
void BST::TravelNLR() {
    NLR(this->root);
}
void BST::TravelLNR() {
    LNR(this->root);

}
void BST::TravelLRN() {
    LRN(this->root);
}
Node* BST::search_x(int k) {
    Node* p = this->root;
    while (p != nullptr) {
        if (p->Getkey() == k) return p;
        if (p->Getkey() > k) p = p->Getleft();
        else p = p->Getright();
    }
    return nullptr;
}
int BST::SumOfBST()
{
    int sum = 0;
    Node* r = this->root;
    if (r != nullptr) {
        NLR(r->Getleft());
        NLR(r->Getright());
        sum += r->Getkey();
    }
    return sum;
}
int BST::LargestInt()
{
    Node* r = this->root;
    if (r != nullptr) {
        r = r->Getright();
    }
    return r->Getkey();
}
int BST::SmallestInt()
{
    Node* r = this->root;
    if (r != nullptr) {
        r = r->Getleft();
    }
    return r->Getkey();
}
int BST::CountNode()
{
    int cnt = 0;
    Node* r = this->root;
    if (r != nullptr) {
        NLR(r->Getleft());
        NLR(r->Getright());
        cnt++;        
    }
    return cnt;
}
int BST::CountLeaf()
{
    int cnt = 0;
    Node* r = this->root;
    if (r != nullptr) {
        NLR(r->Getleft());
        NLR(r->Getright());
        if (r->Getleft() == nullptr && r->Getright() == nullptr) {
            cnt++;
        }
    }
    return cnt;
}
void BST::deleteNode(Node* n) {
    Node* p = n;
    if (n == nullptr) return;
    if (p->Getleft() == nullptr && p->Getright() == nullptr) {
        if (p->Getparent()->Getleft() == n) {
            p->Getparent()->Setleft(nullptr);
        }
        else {
            p->Getparent()->Setright(nullptr);
        }
        delete n;
    }
    else {
        if (p->Getright() != nullptr) {
            p = p->Getright();
            while (p->Getleft() != nullptr)//
                p = p->Getleft();
            n->Setkey(p->Getkey());
            if (p->Getright() == nullptr) {
                if (p->Getparent()->Getleft() == p) {
                    p->Getparent()->Setleft(nullptr);
                }
                else {
                    p->Getparent()->Setright(nullptr);
                }
            }
            else {
                if (p->Getparent()->Getleft() == p) {
                    p->Getparent()->Setleft(p->Getright());
                    p->Getright()->Setparent(p->Getparent());
                }
                else {
                    p->Getparent()->Setright(p->Getright());
                    p->Getright()->Setparent(p->Getparent());
                }
            }
            delete p;
            return;

        }
        else {
            p = p->Getleft();

            while (p->Getright() != nullptr)//
                p = p->Getright();

            n->Setkey(p->Getkey());
            if (p->Getleft() == nullptr) {
                if (p->Getparent()->Getleft() == p) {
                    p->Getparent()->Setleft(nullptr);
                }
                else {
                    p->Getparent()->Setright(nullptr);
                }
            }
            else {
                if (p->Getparent()->Getleft() == p) {
                    p->Getparent()->Setleft(p->Getleft());
                    p->Getleft()->Setparent(p->Getparent());
                }
                else {
                    p->Getparent()->Setright(p->Getleft());
                    p->Getleft()->Setparent(p->Getparent());
                }
            }
            delete p;
            return;
        }
    }
}