#include"BSTree.h"
BSTree SearchBSTree(BSTree T, int key) {
	//���Ϊ�� ˵�������� ���ؿ� ����ҵ� Ҳ����
	if (!T || T->data == key) return T;
	//�����ǰ�ڵ�С��Ŀ��ڵ� ���ҵݹ�Ѱ��
	else if (T->data < key) return SearchBSTree(T->right, key);
	//��������ݹ�Ѱ�� 
	else return SearchBSTree(T->left, key);
}
void InsertBSTree(BSTree& T, int key) {
	//�������������в�����ֵΪkey�Ľ��ʱ����  ��ĳ������ֵ����key��ֱ������
	//����д ���ڵ�Ϊ��Ҳ����ȷ���
	if (!T) {
		BSTNode* t = new BSTNode;
		t->data = key; t->left = t->right = NULL;
		T = t;
	}
	else if (T->data > key) InsertBSTree(T->left, key);
	else if(T->data<key)InsertBSTree(T->right, key);
	//if (T == NULL) return;
	//if (T->data > key) {  //�����ǰ�ڵ��key�� �鿴���ӽڵ����
	//	if (T->left == NULL) {//��Ϊ�� ������Ϊkey
	//		BSTNode* b = new BSTNode;
	//		b->data = key; b->left = b->right = NULL;
	//		T->left = b; delete(b);
	//	}
	//	else InsertBSTree(T->left, key);//����ݹ�����Ѱ��
	//}
	//else {
	//	if (T->right == NULL) {
	//		BSTNode* b = new BSTNode;
	//		b->data = key; b->left = b->right = NULL;
	//		T->right = b; delete(b);
	//	}
	//	else InsertBSTree(T->right, key);
	//}
}
void CreateBST(BSTree& T) {
	//ѭ������ֵ ���������뵽������������
	int val; cout << "���������ֵ,����2147483647��ʾ����";
	cin >> val;
	while (val!= 2147483647)
	{
		InsertBSTree(T, val);
		cin >> val;
	}
}
void DeleteBST(BSTree& T, int val) {
	BSTNode* pre = T;
	BSTNode* cur = T;
	while (cur&&cur->data != val) {
		pre = cur;
		if (cur->data > val)cur = cur->left;
		else cur = cur->right;
	}
	//����λ����ʱ ҪôcurֵΪval ������ǲ�����ֵΪval�Ľ��
	if (!cur) {
		cout << "������ֵΪ" << val << "�Ľ��"; return;
	}
	//����Ҫ�ж�cur��������ϵ 
	if (cur->left ==NULL&& cur->right == NULL) { //��ΪҶ�ӽڵ� ֱ��ɾ������
		if (cur == pre->left) pre->left = NULL;
		else pre->right == NULL;
	}
	else if (cur->left == NULL || cur->right == NULL) { 
		//��ֻ����������� ָ���������ڵ㼴��
		if (cur == pre->left) pre->left = cur->left == NULL ? cur->right : cur->left;
		else pre->right = cur->left == NULL ? cur->right : cur->left;
	}
	else {
		//��������������Ϊ�� Ҫ��cur�滻Ϊ������������и��ڵ�(����cur)��ǰ�����
		//Ҳ����cur�����������ҽ�� �ɱ�֤�������������
		BSTNode* left = cur; BSTNode* right = cur->left;
		while (right->right!= NULL) {
			left = right; right = right->right;
		}
		left->right = NULL;
		right->left = cur->left;
		right->right = cur->right;
		if (cur == pre->left)pre->left = right;
		else pre->right = right;
		
		
	}
	delete(cur);
}
void MidTraverse(BSTree T) {
	if (T->left != NULL) MidTraverse(T->left);
	cout << T->data << "->";
	if (T->right != NULL) MidTraverse(T->right);
}