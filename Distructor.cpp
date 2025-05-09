#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Distructor-------------------
AVL_Tree::~AVL_Tree(){						//Destructor
	DestroyTree(head);
}
