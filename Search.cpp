#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Search Method-------------------
bool AVL_Tree::AVL_Search(int k){
	AVL_Node *temp;
	temp=root;
	while(temp!=0){
		if(temp->key==k){
			return true;						//Is key of current node is same as k then return pointer
		}
		else if(temp->key>k){		//If k is smaller then current node key and there is left child then move to left
			temp=temp->LChild;
		}
		else if(temp->key<k){		//If k is greater then current node key and there is right child then move to right
			temp=temp->RChild;
		}
	}
	return false;
}
