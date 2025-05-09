#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Delete Method-------------------
void AVL_Tree::AVL_Delete(int k){
	AVL_Node *t=head,*p=root,*q,*r,*s,*l;
	AVL_Node *arr[node];
	int bal[node];
	s=p;
	int top=-1;
	if(!AVL_Search(k)){			//If key is not present then return
		cout<<"Key is not present to delete\n";
		return;
	}
	arr[++top]=head;
	bal[top]=-1;
	while(true){				//Finding the appropate position
		if(k<p->key){
			arr[++top]=p;		//Keep track the path from root to delete node
			bal[top]=1;			//If it moves left from current node the store 1
			p=p->LChild;
		}
		else if(k>p->key){
			arr[++top]=p;		//Keep track the path from root to delete node
			bal[top]=-1;		//If it moves right from current node the store -1
			p=p->RChild;
		}
		else{
			break;
		}
	}
	if(p->LChild==0 || p->RChild==0){	//If deleting node is leaf ot single child
		if(p->LChild==0){
			arr[++top]=p;
			bal[top]=1;
		}
		else{
			arr[++top]=p;
			bal[top]=-1;
		}
	}
	else{								//If deleting node have both sub tree then replace with inorder predecessor
		arr[++top]=p;
		bal[top]=1;
		q=p;
		p=p->LChild;
		arr[++top]=p;					//Keep track of path , becuase we are now deleting in order predecessor
		bal[top]=-1;
		while(p->RChild){
			p=p->RChild;
			arr[++top]=p;
			bal[top]=-1;
		}
		q->key=p->key;
	}
	node--;								//Decrement node count by 1
	cout<<"Deletion successful...\n";
	if(bal[top]==1){					//Shifting node pointer of deleting node to its parent
		if(bal[top-1]==1){
			arr[top-1]->LChild=arr[top]->RChild;
		}
		else{
			arr[top-1]->RChild=arr[top]->RChild;
		}
	}
	else{
		if(bal[top-1]==1){
			arr[top-1]->LChild=arr[top]->LChild;
		}
		else{
			arr[top-1]->RChild=arr[top]->LChild;
		}
	}
	delete p;							//Delete the node
	top--;
	while(arr[top]!=head){				//We examine the path deleted node to head for imbalance
		s=arr[top];
		if(s->bf==bal[top]){			//If subtree pointing by 's' is inclind towerds left or right and we are deleted in that direction, then balance factor become 0
			s->bf=0;
		}
		else if(s->bf==0){				//If the subtree pointing by 's' is already bf=0 then by deleting we make bf=1 or -1
			s->bf=-1*bal[top];
			return;
		}
		else{
			p=s;						//If the subtree pointing by 's' is bf=1 or -1 already and we are deleted from shortest side of tree then tree got imbalance
			if(bal[top]==1){			// point the opposite subtree
				q=s->RChild;
			}
			else{
				q=s->LChild;
			}
			if(q->bf==0){				//If opposite subtree has bf=0 we required a single rotation
				if(bal[top]==1){
					p->RChild=q->LChild;
					q->LChild=p;
				}
				else{
					p->LChild=q->RChild;
					q->RChild=p;
				}
				//-------------update balance factor-------------------
				q->bf=bal[top];
				//-----------set parent pointing to the node 'q'--------------
				
				if(bal[top-1]==1){
					arr[top-1]->LChild=q;
				}
				else{
					arr[top-1]->RChild=q;
				}
				root=head->RChild;
				return;
			}
			else if(q->bf==-1*bal[top]){		//This condition is for check single rotation LL or RR and after we have to check remaining node for imbalance
				if(bal[top]==1){
					p->RChild=q->LChild;
					q->LChild=p;
				}
				else{
					p->LChild=q->RChild;
					q->RChild=p;
				}
				//-------------update balance factor-------------------
				q->bf=0;
				p->bf=0;
				//-----------set parent pointing to the node 'q'--------------
				if(bal[top-1]==1){
					arr[top-1]->LChild=q;
				}
				else{
					arr[top-1]->RChild=q;
				}
				root=head->RChild;
			}
			else{			//This is for check double rotation
				if(bal[top]==1){
					r=q->LChild;
					p->RChild=r->LChild;
					q->LChild=r->RChild;
					r->LChild=p;
					r->RChild=q;
				}
				else{
					r=q->RChild;
					p->LChild=r->RChild;
					q->RChild=r->LChild;
					r->RChild=p;
					r->LChild=q;
				}
				//-----------set parent pointing to the node 'r'--------------
				if(bal[top-1]==-1){
					arr[top-1]->RChild=r;
				}
				else{
					arr[top-1]->LChild=r;
				}
				//-------------update balance factor-------------------
				if(r->bf==-1*bal[top]){
					p->bf=bal[top];
					q->bf=0;
				}
				else if(r->bf==0){
					p->bf=0;
					q->bf=0;
				}
				else{
					p->bf=0;
					q->bf=-1*bal[top];
				}
				r->bf=0;
			}
		}
		top--;
	}
	root=head->RChild;			//Set the root if root got distrub
}
