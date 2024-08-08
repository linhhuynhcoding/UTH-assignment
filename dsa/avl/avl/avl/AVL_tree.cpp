//AVL_tree.cpp
#include "AVL_tree.h"
#include <iostream>
#include "Node.h"
using namespace std;
AVL_tree::AVL_tree()
{
    //ctor
    this->root = nullptr;
}


AVL_tree::~AVL_tree()
{
    //dtor
}


bool AVL_tree::InsertNode(Node* n) {
    Node* p = this->root;
    Node* T = nullptr;
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


    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    n->Setparent(T);
    /////////////////////////////////////////
    Node* x = n;
    while (x != nullptr) {
        Node* left = x->Getleft();
        Node* right = x->Getright();

        int bal = GetHeight(left) - GetHeight(right);
        if (abs(bal) < 2 ){
            
        }
        else if (bal == 2) {
            if (x->Getleft()->Getleft() != nullptr)// LEFT-LEFT
            {
                this->RightRotate(x);
                /*parentX = x->Getparent();
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else parentX->Setleft(x);*/
            }
            else // Left-Right
            {
                Node* xleft = x->Getleft();
                this->LeftRotate(xleft);
                this->RightRotate(x);
            }
        }
        else {
            if (x->Getright()->Getright() != nullptr)  // RIGHT-RIGHT
            {
                this->LeftRotate(x);
                /*parentX = x->Getparent();
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else parentX->Setleft(x);*/
            }
            else // Right-left
            {
                Node* xright = x->Getright();
                this->RightRotate(xright);
                this->LeftRotate(x);
            }        
        }
        if (x == nullptr) break;
        if (x->Getparent() == nullptr)
            this->root = x;           
        x = x->Getparent();
    }

    return true;

}
Node* AVL_tree::InsertNode(Node* r, Node* p) {
    if (r == nullptr) {
        r = p;
        return r;
    }
    if (r->Getkey() == p->Getkey())
        return nullptr;
    else if (r->Getkey() > p->Getkey()) {
        r->Setleft(InsertNode(r->Getleft(), p));
        return r->Getleft();
    }
    else {
        r->Setright(InsertNode(r->Getright(), p));
        return r->Getright();
    };
    //
 /*   r->Setheight ( 1 + max(r->Getleft()->Getheight(),r->Getright()->Getheight()));


    int valBalance = r->Getleft()->Getheight() - r->Getright()->Getheight();


    if(valBalance>1&&r->Getleft()->Getkey()>p->Getkey())
        this->RightRotate(r);*/


}




void AVL_tree::InsertNodeRe(Node* p) {
    this->root = InsertNode(this->root, p);
}
void AVL_tree::NLR(Node* r) {
    if (r != nullptr) {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
void AVL_tree::LNR(Node* r) {
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << " ";
        LNR(r->Getright());
    }

    //sinh vien code
}
void AVL_tree::LRN(Node* r) {
    if (r != nullptr) {
        LRN(r->Getleft());
        LRN(r->Getright());
        cout << r->Getkey() << "\n";
    }
    //sinh vien code
}
void AVL_tree::TravelNLR() {
    NLR(this->root);
}
void AVL_tree::TravelLNR() {
    LNR(this->root);
}
void AVL_tree::TravelLRN() {
    LRN(this->root);
}
Node* AVL_tree::search_x(int k) {
    //sinh vien code
    Node* r = this->root;
    while (r->Getkey() != k || r != nullptr) {
        if (k > r->Getkey()) {
            r = r->Getright();
        }
        else {
            r = r->Getleft();
        }
    }
    return r;
}
void AVL_tree::deleteNode(Node* n) {
    Node* p = n;
    if (p->Getleft() == nullptr && n->Getright() == nullptr) {
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
            if (p->Getright() != nullptr) p->Getparent()->Setleft(p->Getright());
            delete p;
        }
        else {
            p = p->Getleft();
            while (p->Getright() != nullptr)//
                p = p->Getright();
            n->Setkey(p->Getkey());
            if (p->Getleft() != nullptr) p->Getparent()->Setright(p->Getleft());
            delete p;
        }
    }

}
void AVL_tree::LeftRotate(Node*& P) {
    Node* Q;
    Node* T;
    Q = P->Getright();
    T = Q->Getleft();
    P->Setright(T);
    Q->Setleft(P);

    if (T != nullptr)
        T->Setparent(P);
    Q->Setparent(P->Getparent()); 
    if (P->Getparent() != nullptr)
        P->Getparent()->Setright(Q);
    P->Setparent(Q);
}
void AVL_tree::RightRotate(Node*& P) {
    Node* Q;
    Node* T;
    Q = P->Getleft();
    T = Q->Getright();
    P->Setleft(T);
    Q->Setright(P);
    if (T != nullptr)
        T->Setparent(P);
    Q->Setparent(P->Getparent());
    if (P->Getparent() != nullptr)
        P->Getparent()->Setleft(Q);
    P->Setparent(Q);
    
    // sinh vien code   
}

int AVL_tree::GetHeight(Node* p) {
    if (p == nullptr) return 0;
    else
        return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}
