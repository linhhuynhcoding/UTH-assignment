#include "NODE.h"

Node::Node()
{

    //ctor
    this->key = 0;
    this->fre = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}
Node::Node(int k) {
    //ctor
    this->key = k;
    this->fre = 1;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}
Node::~Node()
{
    //dtor
}
