#include<iostream>
#include<fstream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Print Method-------------------
void AVL_Tree::AVL_Print(const char *filename){
	AVL_Node *tempCurr=root;
	ofstream f(filename);
	f<<"digraph G{\n";
	f<<"node [shape = record,height=.1];\n";
	if(root==0){
		f<<"}";
		return;
	}
	int p=node,top=-1;
	AVL_Node *print[p];
	print[++top]=tempCurr;
	for(int i=0;i<p;i++){		//---------------Take all nodes in an array------------------
		if(print[i]->LChild!=0){
			print[++top]=print[i]->LChild;
		}
		if(print[i]->RChild!=0){
			print[++top]=print[i]->RChild;
		}
	}
	for(int i=0;i<p;i++){		//-------------------Add all node to the file-----------------------
		f<<"node"<<print[i]->key<<"[label = \"<f0> |<f1>"<<" "<<print[i]->key<<"|<f2> "<<print[i]->bf<<"|<f3> \"];\n";
	}
	
	for(int i=0;i<p;i++){		//----------------------Add all edges to the file--------------------------
		if(print[i]){
			if(print[i]->LChild!=0){
				f<<"\"node"<<print[i]->key<<"\":"<<"f0 -> "<<"\"node"<<print[i]->LChild->key<<"\":"<<"f1;\n";
			}
			if(print[i]->RChild!=0){
				f<<"\"node"<<print[i]->key<<"\":"<<"f3 -> "<<"\"node"<<print[i]->RChild->key<<"\":"<<"f1;\n";
			}
		}
	}
	f<<"}";
	f.close();								//Close the file
}
