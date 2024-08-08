//Node.cpp

#include "Node.h"
Node::Node()
{
    //ctor
    this->key = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}
Node::Node(int k) {
    //ctor
    this->key = k;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}
Node::~Node()
{
    //dtor
}
