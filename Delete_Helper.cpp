#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------To delete-------------------
void AVL_Tree::DestroyTree(AVL_Node *n){	//It will delete all nodes below pointer 'n' including 'n' node, If we pass head pointer it will delete full tree without memory lick
	if(n){
		DestroyTree(n->LChild);
		DestroyTree(n->RChild);
		delete n;
	}
}
