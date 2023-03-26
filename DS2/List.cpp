#include"List.h"

void InitList(LinkedList& l) {
	//构造一个空的单链表
	l = new  LNode;
	l->next = NULL;
}
LinkedList InitList() {
	LinkedList l;
	InitList(l);
	return l;
}
int GetElem(LinkedList l, int i) {
	//在带有头结点的单链表l中根据序号i获取元素的值,并用e接收
	LNode* p = l->next; int j = 1;
	while (p && j < i) { //要确保p不为空 否则p->next就会报错
		p = p->next;
		j++;
	}
	//若i太大 超过有数据的长度 p就会超出正常范围 指向空
	//若i小于等于0 同样操作无法正常弯完成
	if (!p || j > i) return -1;
	return p->data;
}
Status GetElem(LinkedList l, int i, int& e) {
	//在带有头结点的单链表l中根据序号i获取元素的值,并用e接收
	LNode* p = l->next; int j = 1;
	while (p && j < i) { //要确保p不为空 否则p->next就会报错
		p = p->next;
		j++;
	}
	//若i太大 超过有数据的长度 p就会超出正常范围 指向空
	//若i小于等于0 同样操作无法正常弯完成
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}
int LocateElem_pos(LinkedList l, int e) {
	int pos = 1;
	LNode* p = l->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p == NULL ? -1 : pos;
}
LNode* LocateElem_ele(LinkedList l, int e) {
	LNode* p = l->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}
Status ListInsert(LinkedList& l, int i, int e) {
	LNode* p = l; int j = 0;
	//将p定位到i前面的位置
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	LNode* t = new LNode;
	t->data = e;
	t->next = p->next;
	p->next = t;
	return OK;
}
Status ListDeleteByIndex(LinkedList& l, int i) {
	LNode* p = l->next; int j = 1;
	//将p定位到i前面的位置
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
void ListDeleteByValue(LinkedList& l, int i) {
	LNode* p = l; 
	//将p定位到i前面的位置
	while (p->next && p->next->data!=i) {
		p = p->next;
	}
	if (!(p->next)) return;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
}
void CreateList_H(LinkedList& l, int n) {
	InitList(l);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		insert_front(l, x);
	}
}
void CreateList_R(LinkedList& l, int n) {
	InitList(l);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		insert_back(l, x);
	}
}
LinkedList getList_H(int n) {
	LinkedList l;
	CreateList_H(l, n);
	return l;
}
LinkedList getList_R(int n) {
	LinkedList l;
	CreateList_R(l, n);
	return l;
}
bool contain(LinkedList l, int e) {
	if (l->next == NULL) return 0;
	LNode* p = l->next;
	while (p && p->data != e) p = p->next;
	return p != NULL;
}
void showList(LinkedList l) {
	l = l->next;
	while (l != NULL) {
		cout << l->data;
		if (l->next != NULL) cout << "->";
		l = l->next;
	}
}
void insert_front(LinkedList& l, int e) {
	LNode* p = l;
	LNode* t = new LNode;
	t->data = e;
	t->next = p->next;
	p->next = t;
}
void insert_back(LinkedList& l, int e) {
	LNode* p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	LNode* t = new LNode;
	t->data = e;
	t->next = NULL;
	p->next = t;
}
void deleteList(LinkedList l) {

	LNode* p = l->next;
	while (p != NULL) {
		delete l;
		l = p; p = p->next;
	}
	delete l;
}
void MergeList(LinkedList& l1, LinkedList l2) {
	//求得两表的并集,将l2中的l1没有的元素加入到l1尾部
	LNode* l2p = l2->next;
	while (l2p != NULL) {
		if (!contain(l1, l2p->data)) insert_back(l1, l2p->data);
		l2p = l2p->next;
	}
	deleteList(l2);
}
void MergeListless(LinkedList& l1, LinkedList& l2) {
	//求两个有序链表的交集 将结果保存到l1
	LNode* node1 = l1->next; LNode* node2 = l2->next;
	while (node1 != NULL) {
		if (!contain(l2, node1->data)) {
			//如果l1中的元素l2中没有 就删除
			int del = node1->data; node1 = node1->next;
			ListDeleteByValue(l1, del);
		}
		else {
			node1 = node1->next;
		}
	}
}
LinkedList Merge_of_seqList(LinkedList& l1, LinkedList& l2) {
	//将两个有序表合并 使得合并后仍有序 创建新表头利用表中节点比较大小后加到新表后边即可
	LinkedList l3;
	InitList(l3);
	LNode* p = l3;
	LNode* q = l1->next;
	LNode* r = l2->next;
	while (q && r) {
		if (q->data <= r->data) {
			p->next = q;
			q = q->next;
			p = p->next;
		}
		else {
			p->next = r;
			r = r->next;
			p = p->next;
		}
	}
	p->next = q ? r : q;
	delete l1, l2;
	return l3;
}
LNode* getMax(LinkedList list) {
	if (list->next == NULL) return NULL;
	LNode* p = list->next;
	LNode* res = NULL;
	int max = INT32_MIN;
	while (p != NULL)
	{
		if (p->data > max) {
			max = p->data;
			res = p;
		}
		p = p->next;
	}
	return res;
}
LinkedList reverse1(LinkedList& list) {
	//反转链表
	LNode* newHead = new LNode; //新的头节点
	LNode* p = list;            //遍历将新的头节点的next设置为原来链表的最后一个节点
	while (p->next != NULL) p = p->next;
	newHead->next = p;
	reverseNode1(list, list->next);//递归逆转指针
	list->next->next = NULL;       //这时原来的头节点和第一个节点形成闭环 将第一节点的next置为空
	delete(list);               //删除原来的头节点
	return newHead;
}
void reverseNode1(LNode* pre, LNode* cur) {
	if (cur->next != NULL) reverseNode1(cur, cur->next);
	cur->next = pre;
}

void reverse2(LinkedList& list) {
	if (list->next == NULL) return;
	list->next = reverseNode2(list, list, list->next);   //头节点的next指向反转后的第一个非头节点     
}
LNode* reverseNode2(LNode* list, LNode* pre, LNode* cur) {
	//返回反转后的第一个data域不为空的节点
	if (cur == NULL) return pre; //此时pre为原链表最后一个节点 返回
	LNode* res = reverseNode2(list, cur, cur->next); //为res赋值
	cur->next = pre;							//反转指针
	if (pre == list) cur->next = NULL;			//如果pre为头节点 就让第一个节点的next指向空
	return res;									//始终返回反转后的第一个非头节点
}
void divideListByPN(LinkedList& l1, LinkedList& A, LinkedList& B) {
	//将l1表划分成正负两部分 储存在A B中
	LNode* a = A; LNode* b = B;
	l1 = l1->next;
	while (l1!=NULL)
	{
		if (l1->data > 0) {
			a->next = l1;
			a = a->next;
		}
		else {
			b->next = l1;
			b = b->next;
		}
		l1 = l1->next;
	}
	a->next = b->next = NULL;
}
void RecurPre(LinkedList l, int& max, int& num, int& aver) {
	//接收链表的头节点 调用方法从第一个结点开始递归
	Recursion(l->next, max, num, aver);
}
void Recursion(LinkedList l, int& max, int& num, int& aver) {
	//递归过程中更新最大值和个数 aver在递归过程中为前n个结点的和
	if (l == NULL) { 
		//到链表结尾 更新平均值 除个数 如果个数为0则不除
		if(num!=0)
		aver /= num; 
		return;
	}
	//更新最大值
	if (l->data > max) max = l->data;
	//更新个数和当前 "平均值"
	num++; aver += l->data;
	//递归
	Recursion(l->next, max, num, aver);
}