#include<iostream>
using namespace std;
typedef struct BSTNode {
	int data;
	struct BSTNode* left,*right;
}BSTNode,*BSTree;  //节点为BSTNode 树根为BSTree
BSTree SearchBSTree(BSTree T, int key); //寻找二叉搜索树中是否存在值为key的节点
void InsertBSTree(BSTree& T, int key); //二叉搜索树的数据插入
void CreateBST(BSTree& T);
void DeleteBST(BSTree& T, int val);
void MidTraverse(BSTree T);