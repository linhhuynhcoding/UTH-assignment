//NODE.h

#pragma once

class Node
{
public:
    Node();
    Node(int);
    virtual ~Node();

    Node* Getleft() { return left; }
    void Setleft(Node* val) { left = val; }
    Node* Getright() { return right; }
    void Setright(Node* val) { right = val; }
    Node* Getparent() { return parent; }
    void Setparent(Node* val) { parent = val; }
    int Getkey() { return key; }
    void Setkey(int val) { key = val; }

    int Getfre() { return fre; }
    void Upfre() { fre++; return; }
    void Downfre() { fre--; return; }

protected:

private:
    Node* left;
    Node* right;
    Node* parent;
    int key;
    int fre;
};



