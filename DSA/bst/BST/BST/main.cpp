//main.cpp

#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST* tree = new BST();
    Node* n;
    n = new Node(10);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(9);
    tree->InsertNode(n);
    n = new Node(3);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(8);
    tree->InsertNode(n);
    n = new Node(4);
    tree->InsertNode(n);
    n = new Node(1);
    tree->InsertNode(n);
    n = new Node(15);
    tree->InsertNode(n);

    tree->TravelLNR(); cout << "\n";
    tree->deleteNode(tree->Getroot());
    tree->deleteNode(tree->Getroot());
    tree->deleteNode(tree->Getroot());
    tree->TravelLNR();



    return 0;
}
