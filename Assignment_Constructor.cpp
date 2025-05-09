#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Assignment constructor-------------------
AVL_Tree & AVL_Tree::operator=(const AVL_Tree &T){
	DestroyTree(this->root);			//First delete all nodes and then assign the existing object to prevent memory lick
	CopyTree(this->root,T.root);		//Copy all tree to LHS object
	this->node=T.node;					//Copy the total number of nodes
	this->root=this->head->RChild;		//Make our tree right subtree of head
	return *this;
}
