#include"BSTree.h"
int main_bst() {
	BSTree T = NULL;
	CreateBST(T);
	MidTraverse(T);
	DeleteBST(T, 78);
	MidTraverse(T);
	return 0;
}