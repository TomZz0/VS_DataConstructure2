#include<iostream>
using namespace std;
typedef struct BSTNode {
	int data;
	struct BSTNode* left,*right;
}BSTNode,*BSTree;  //�ڵ�ΪBSTNode ����ΪBSTree
BSTree SearchBSTree(BSTree T, int key); //Ѱ�Ҷ������������Ƿ����ֵΪkey�Ľڵ�
void InsertBSTree(BSTree& T, int key); //���������������ݲ���
void CreateBST(BSTree& T);
void DeleteBST(BSTree& T, int val);
void MidTraverse(BSTree T);