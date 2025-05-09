#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Copy method to copy the tree-------------------
void AVL_Tree::CopyTree(AVL_Node *ToNode,const AVL_Node *FromNode){		//To copy the tree
	if(FromNode==0){
		ToNode=0;
	}
	else{
		ToNode=new AVL_Node(FromNode->key);
		ToNode->bf=FromNode->bf;
		CopyTree(ToNode->LChild,FromNode->LChild);
		CopyTree(ToNode->RChild,FromNode->RChild);
	}
}
