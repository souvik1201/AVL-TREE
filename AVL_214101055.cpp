#include<iostream>
#include<fstream>
#include<string.h>
#include "AVL_Node.h"
#include "AVL_Tree.h"
using namespace std;
int main(){
	AVL_Tree a;
	int k,n;
	char c[100];
	while(1){
		cout<<"\n\n";
		cout<<"Enter 1 to insert on AVL Tree\n";
		cout<<"Enter 2 to delete on AVL Tree\n";
		cout<<"Enter 3 to search on AVL Tree\n";
		cout<<"Enter 4 to print on AVL Tree\n";
		cout<<"Enter 5 to Exit\n";
		cout<<"Enter your choise : ";
		cin>>n;
		if(n==1){
			cout<<"Enter your key to insert : ";
			cin>>k;
			a.AVL_Insert(k);
		}
		else if(n==2){
			cout<<"Enter your key to delete : ";
			cin>>k;
			a.AVL_Delete(k);
		}
		else if(n==3){
			cout<<"Enter your key to search: ";
			cin>>k;
			if(a.AVL_Search(k))
				cout<<"Key is present in tree\n";
			else
				cout<<"NOT present in tree\n";
		}
		else if(n==4){
			cout<<"We are printing your graph type a name to save your file : ";
			cin>>c;
			strcat(c,".gv");
			a.AVL_Print(c);
			cout<<"saved as "<<c<<".......\n";
		}
		else if(n==5){
			return 0;
		}
		else{
			cout<<"Wrong input";
		}
	}
}
