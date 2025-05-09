#ifndef AVL_TREE_H
#define AVL_TREE_H
class AVL_Tree{
	private:
		AVL_Node *root,*head;
		int node;
	public:
		AVL_Tree();							//Default constructor
		AVL_Tree(const AVL_Tree &T);		//Copy constructor
		AVL_Tree&operator=(const AVL_Tree &T);	//Assignment constructor
		void AVL_Insert(int k);
		void AVL_Delete(int k);
		bool AVL_Search(int k);
		void AVL_Print(const char *filename);
		void DestroyTree(AVL_Node *n);
		void CopyTree(AVL_Node *ToNode,const AVL_Node *FromNode);
		~AVL_Tree();
};
#endif
