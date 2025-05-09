#ifndef AVL_NODE_H
#define AVL_NODE_H
class AVL_Node{			//Node of AVL tree
	private:
		int key;
		int bf;
		AVL_Node *LChild, *RChild;
		friend class AVL_Tree;		//out side class private elements are only access by AVL_tree class
	public:
		AVL_Node(int k){
			key=k;
			bf=0;
			LChild=0;
			RChild=0;
		}
};
#endif
