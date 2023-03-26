#include"CirCleList.h"
void InitCList(CLinkedList& l) {
	//����һ���յĵ�����
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
void EnterQueue(CLQueue& cq, int val) { //��β�����
	CLNode* t = new CLNode;
	t->data = val;
	t->next = cq.rear->next;
	cq.rear->next = t;
	cq.rear = t;
}
void DeQueue(CLQueue& cq) {
	if (isEmpty(cq)) {
		cout << "����Ϊ�� �޷�����"; return;
	}
	//���Ҫ���ӵĽ�� ��������ͷ�
	CLNode* des = cq.rear->next->next;
	//���ֻ��һ����� 
	if (cq.rear->next->next == cq.rear) {
		cq.rear = cq.rear->next; cq.rear->next = cq.rear;
	}
	//������ͷ���ָ����һ��
	else cq.rear->next->next = des->next;
	delete(des);
}
void SetEmpty(CLQueue& cq) {
	while (!isEmpty(cq)) DeQueue(cq);
}
void showCLQueue(CLQueue cq) {
	if (cq.rear == cq.rear->next) {
		cout << "����Ϊ��"; return;
	}
	CLNode* c = cq.rear->next->next;
	while (c!=cq.rear->next)
	{
		cout << c->data << " ";
		c = c->next;
	}
	cout << "\n";
}