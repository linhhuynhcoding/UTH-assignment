//BST.h
#pragma once
#include "NODE.h"


class BST
{
public:
    BST();
    virtual ~BST();

    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    bool InsertNode(Node*);
    bool InsertNodeRe(Node*, Node*);
    void deleteNode(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    void NLR(Node*);
    void LNR(Node*);
    void LRN(Node*);
    Node* search_x(int);


    int SumOfBST();
    int LargestInt();
    int SmallestInt();
    int CountNode();
    int CountLeaf();

protected:

private:
    Node* root;
};
