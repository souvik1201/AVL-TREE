#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Default constructor-------------------
AVL_Tree::AVL_Tree(){
	head=new AVL_Node(0);
	root=0;
	node=0;
}
