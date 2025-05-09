#include<iostream>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
//----------------Insert Method-------------------
void AVL_Tree::AVL_Insert(int k){
	AVL_Node *t,*s,*p,*q,*r;
	int a;
	if(root==0){				//For the first element
		t=new AVL_Node(k);
		head->RChild=t;
		root=t;
		node++;
		cout<<"Insert successfull\n";
		return;
	}
	t=head;
	p=root;
	s=p;
	if(AVL_Search(k)){					//If key is present then return
		cout<<"Key that you have entered is already present\n";
		return;
	}
	//Try to find closest node which may be imbalance due to insertion
	while(1){
		if(k<p->key){
			q=p->LChild;
			if(!q){
				q=new AVL_Node(k);
				p->LChild=q;
				node++;
				cout<<"Insert successful\n";
				break;
			}
			else{
				if(q->bf!=0){
					t=p;
					s=q;		//S pointing to a node which may imbalance after insertion
				}
				p=q;
			}
		}
		else if(k>p->key){
			q=p->RChild;
			if(!q){
				q=new AVL_Node(k);
				p->RChild=q;
				node++;
				cout<<"Insertion successfull\n";
				break;
			}
			else{
				if(q->bf!=0){
					t=p;
					s=q;		//S pointing to a node which may imbalance after insertion
				}
				p=q;
			}
		}
	}
	//----------------Adjust balance factor----------------------
	if(k<s->key){
		a=1;
		p=s->LChild;
		r=p;
	}
	else{
		a=-1;
		p=s->RChild;
		r=p;
	}
	while(p!=q){			//We are adjust balance factor between all nodes 'p' and 'q'
		if(k<p->key){
			p->bf=1;
			p=p->LChild;
		}
		else if(k>p->key){
			p->bf=-1;
			p=p->RChild;
		}
	}
	//---------------------Balancing---------------------------------
	if(s->bf==0){
		s->bf=a;
	}
	else if(s->bf==-1*a){
		s->bf=0;
	}
	else if(s->bf==a){
		if(r->bf==a){//-----------------single roration-------------------
			if(a==-1){
				p=r;
				s->RChild=r->LChild;
				r->LChild=s;
				r->bf=0;
				s->bf=0;
			}
			else if(a==1){
				p=r;
				s->LChild=r->RChild;
				r->RChild=s;
				r->bf=0;
				s->bf=0;
			}
		}
		else if(r->bf==-1*a){//---------------double rotation--------------------------
			
			if(a==-1){
				p=r->LChild;
				r->LChild=p->RChild;
				p->RChild=r;
				s->RChild=p->LChild;
				p->LChild=s;
			}
			else if(a==1){
				p=r->RChild;
				r->RChild=p->LChild;
				p->LChild=r;
				s->LChild=p->RChild;
				p->RChild=s;
			}
			//-------------update balance factor-------------------
			if(p->bf==a){
				s->bf=-1*a;
				r->bf=0;
			}
			else if(p->bf==0){
				s->bf=0;
				r->bf=0;
			}
			else if(p->bf==-1*a){
				s->bf=0;
				r->bf=a;
			}
			p->bf=0;
		}
		//-----------set parent pointing to the node 'p'--------------
		if(s==t->RChild){
			t->RChild=p;
		}
		else{
			t->LChild=p;
		}
	}
	root=head->RChild;				//Set root to right child of head if root got disturb
}
