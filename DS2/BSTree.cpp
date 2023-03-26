#include"BSTree.h"
BSTree SearchBSTree(BSTree T, int key) {
	//如果为空 说明不存在 返回空 如果找到 也返回
	if (!T || T->data == key) return T;
	//如果当前节点小于目标节点 向右递归寻找
	else if (T->data < key) return SearchBSTree(T->right, key);
	//否则向左递归寻找 
	else return SearchBSTree(T->left, key);
}
void InsertBSTree(BSTree& T, int key) {
	//当二叉搜索树中不存在值为key的结点时加入  若某个结点的值等于key会直接跳过
	//这样写 根节点为空也能正确添加
	if (!T) {
		BSTNode* t = new BSTNode;
		t->data = key; t->left = t->right = NULL;
		T = t;
	}
	else if (T->data > key) InsertBSTree(T->left, key);
	else if(T->data<key)InsertBSTree(T->right, key);
	//if (T == NULL) return;
	//if (T->data > key) {  //如果当前节点比key大 查看左子节点情况
	//	if (T->left == NULL) {//若为空 就设置为key
	//		BSTNode* b = new BSTNode;
	//		b->data = key; b->left = b->right = NULL;
	//		T->left = b; delete(b);
	//	}
	//	else InsertBSTree(T->left, key);//否则递归向左寻找
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
	//循环输入值 创建结点加入到二叉搜素树中
	int val; cout << "请输入结点的值,输入2147483647表示结束";
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
	//当定位结束时 要么cur值为val 否则就是不存在值为val的结点
	if (!cur) {
		cout << "不存在值为" << val << "的结点"; return;
	}
	//下面要判断cur的子树关系 
	if (cur->left ==NULL&& cur->right == NULL) { //若为叶子节点 直接删除即可
		if (cur == pre->left) pre->left = NULL;
		else pre->right == NULL;
	}
	else if (cur->left == NULL || cur->right == NULL) { 
		//若只有左或右子树 指向子树根节点即可
		if (cur == pre->left) pre->left = cur->left == NULL ? cur->right : cur->left;
		else pre->right = cur->left == NULL ? cur->right : cur->left;
	}
	else {
		//若左右子树都不为空 要将cur替换为子树中序遍历中根节点(就是cur)的前驱结点
		//也就是cur左子树的最右结点 可保证不增加树的深度
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