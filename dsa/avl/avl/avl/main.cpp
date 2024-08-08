#include <iostream>
#include "AVL_tree.h"
#include "Node.h"

using namespace std;

int main() {
	AVL_tree* avl = new AVL_tree();
	for (auto i : { 1,3,5,7,9,12,15,17,21,23,25,27 }) {
		cout << i << " ";
		Node* n = new Node(i);
		avl->InsertNode(n);
		avl->TravelLNR();
		cout << "root:" << avl->Getroot()->Getkey() << " ";
		cout << "hr:" << avl->GetHeight(avl->Getroot()) << " ";
		cout << "\n";
	}
	//avl->LNR(avl->Getroot());
}