#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Copy constructor-------------------
AVL_Tree::AVL_Tree(const AVL_Tree &T){
	CopyTree(this->head,T.head);		//Copy all tree to LHS object
	this->node=T.node;					//Copy the total number of nodes
	this->root=this->head->RChild;		//Make root pointing to the right subtree of head
}
