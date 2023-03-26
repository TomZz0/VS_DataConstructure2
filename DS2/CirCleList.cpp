#include"CirCleList.h"
void InitCList(CLinkedList& l) {
	//构造一个空的单链表
	l = new  CLNode;
	l->next = l;
}
CLinkedList InitCList() {
	CLinkedList l;
	InitCList(l);
	return l;
}
bool isEmpty(CLQueue cq) {
	if (cq.rear == NULL) return 1;
	if (cq.rear == cq.rear->next) return 1;
	return 0;
} 
void EnterQueue(CLQueue& cq, int val) { //从尾部入队
	CLNode* t = new CLNode;
	t->data = val;
	t->next = cq.rear->next;
	cq.rear->next = t;
	cq.rear = t;
}
void DeQueue(CLQueue& cq) {
	if (isEmpty(cq)) {
		cout << "队列为空 无法出队"; return;
	}
	//获得要出队的结点 操作完后释放
	CLNode* des = cq.rear->next->next;
	//如果只有一个结点 
	if (cq.rear->next->next == cq.rear) {
		cq.rear = cq.rear->next; cq.rear->next = cq.rear;
	}
	//否则让头结点指向下一个
	else cq.rear->next->next = des->next;
	delete(des);
}
void SetEmpty(CLQueue& cq) {
	while (!isEmpty(cq)) DeQueue(cq);
}
void showCLQueue(CLQueue cq) {
	if (cq.rear == cq.rear->next) {
		cout << "队列为空"; return;
	}
	CLNode* c = cq.rear->next->next;
	while (c!=cq.rear->next)
	{
		cout << c->data << " ";
		c = c->next;
	}
	cout << "\n";
}