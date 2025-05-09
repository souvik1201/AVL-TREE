AVL: AVL_214101055.o Assignment_Constructor.o Copy_Constructor.o Copy_Helper.o Default_Constructor.o Delete.o Delete_Helper.o Distructor.o Insert.o Print.o Search.o
	g++ AVL_214101055.o Assignment_Constructor.o Copy_Constructor.o Copy_Helper.o Default_Constructor.o Delete.o Delete_Helper.o Distructor.o Insert.o Print.o Search.o
	
AVL_214101055.o: AVL_214101055.cpp AVL_Node.h AVL_Tree.h
	g++ -c AVL_214101055.cpp 
Assignment_Constructor.o: Assignment_Constructor.cpp AVL_Node.h AVL_Tree.h
	g++ -c Assignment_Constructor.cpp
Copy_Constructor.o: Copy_Constructor.cpp AVL_Node.h AVL_Tree.h
	g++ -c Copy_Constructor.cpp
Copy_Helper.o: Copy_Helper.cpp AVL_Node.h AVL_Tree.h
	g++ -c Copy_Helper.cpp
Default_Constructor.o: Default_Constructor.cpp AVL_Node.h AVL_Tree.h
	g++ -c Default_Constructor.cpp
Delete.o: Delete.cpp AVL_Node.h AVL_Tree.h
	g++ -c Delete.cpp
Delete_Helper.o: Delete_Helper.cpp AVL_Node.h AVL_Tree.h
	g++ -c Delete_Helper.cpp
Distructor.o: Distructor.cpp AVL_Node.h AVL_Tree.h
	g++ -c Distructor.cpp
Insert.o: Insert.cpp AVL_Node.h AVL_Tree.h
	g++ -c Insert.cpp
Print.o: Print.cpp AVL_Node.h AVL_Tree.h
	g++ -c Print.cpp
Search.o: Search.cpp AVL_Node.h AVL_Tree.h
	g++ -c Search.cpp
run: a.exe
	./a
clear:
	rm *.o