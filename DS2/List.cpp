#include"List.h"

void InitList(LinkedList& l) {
	//����һ���յĵ�����
	l = new  LNode;
	l->next = NULL;
}
LinkedList InitList() {
	LinkedList l;
	InitList(l);
	return l;
}
int GetElem(LinkedList l, int i) {
	//�ڴ���ͷ���ĵ�����l�и������i��ȡԪ�ص�ֵ,����e����
	LNode* p = l->next; int j = 1;
	while (p && j < i) { //Ҫȷ��p��Ϊ�� ����p->next�ͻᱨ��
		p = p->next;
		j++;
	}
	//��i̫�� ���������ݵĳ��� p�ͻᳬ��������Χ ָ���
	//��iС�ڵ���0 ͬ�������޷����������
	if (!p || j > i) return -1;
	return p->data;
}
Status GetElem(LinkedList l, int i, int& e) {
	//�ڴ���ͷ���ĵ�����l�и������i��ȡԪ�ص�ֵ,����e����
	LNode* p = l->next; int j = 1;
	while (p && j < i) { //Ҫȷ��p��Ϊ�� ����p->next�ͻᱨ��
		p = p->next;
		j++;
	}
	//��i̫�� ���������ݵĳ��� p�ͻᳬ��������Χ ָ���
	//��iС�ڵ���0 ͬ�������޷����������
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
	//��p��λ��iǰ���λ��
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
	//��p��λ��iǰ���λ��
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
	//��p��λ��iǰ���λ��
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
	//�������Ĳ���,��l2�е�l1û�е�Ԫ�ؼ��뵽l1β��
	LNode* l2p = l2->next;
	while (l2p != NULL) {
		if (!contain(l1, l2p->data)) insert_back(l1, l2p->data);
		l2p = l2p->next;
	}
	deleteList(l2);
}
void MergeListless(LinkedList& l1, LinkedList& l2) {
	//��������������Ľ��� ��������浽l1
	LNode* node1 = l1->next; LNode* node2 = l2->next;
	while (node1 != NULL) {
		if (!contain(l2, node1->data)) {
			//���l1�е�Ԫ��l2��û�� ��ɾ��
			int del = node1->data; node1 = node1->next;
			ListDeleteByValue(l1, del);
		}
		else {
			node1 = node1->next;
		}
	}
}
LinkedList Merge_of_seqList(LinkedList& l1, LinkedList& l2) {
	//�����������ϲ� ʹ�úϲ��������� �����±�ͷ���ñ��нڵ�Ƚϴ�С��ӵ��±��߼���
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
	//��ת����
	LNode* newHead = new LNode; //�µ�ͷ�ڵ�
	LNode* p = list;            //�������µ�ͷ�ڵ��next����Ϊԭ����������һ���ڵ�
	while (p->next != NULL) p = p->next;
	newHead->next = p;
	reverseNode1(list, list->next);//�ݹ���תָ��
	list->next->next = NULL;       //��ʱԭ����ͷ�ڵ�͵�һ���ڵ��γɱջ� ����һ�ڵ��next��Ϊ��
	delete(list);               //ɾ��ԭ����ͷ�ڵ�
	return newHead;
}
void reverseNode1(LNode* pre, LNode* cur) {
	if (cur->next != NULL) reverseNode1(cur, cur->next);
	cur->next = pre;
}

void reverse2(LinkedList& list) {
	if (list->next == NULL) return;
	list->next = reverseNode2(list, list, list->next);   //ͷ�ڵ��nextָ��ת��ĵ�һ����ͷ�ڵ�     
}
LNode* reverseNode2(LNode* list, LNode* pre, LNode* cur) {
	//���ط�ת��ĵ�һ��data��Ϊ�յĽڵ�
	if (cur == NULL) return pre; //��ʱpreΪԭ�������һ���ڵ� ����
	LNode* res = reverseNode2(list, cur, cur->next); //Ϊres��ֵ
	cur->next = pre;							//��תָ��
	if (pre == list) cur->next = NULL;			//���preΪͷ�ڵ� ���õ�һ���ڵ��nextָ���
	return res;									//ʼ�շ��ط�ת��ĵ�һ����ͷ�ڵ�
}
void divideListByPN(LinkedList& l1, LinkedList& A, LinkedList& B) {
	//��l1���ֳ����������� ������A B��
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
	//���������ͷ�ڵ� ���÷����ӵ�һ����㿪ʼ�ݹ�
	Recursion(l->next, max, num, aver);
}
void Recursion(LinkedList l, int& max, int& num, int& aver) {
	//�ݹ�����и������ֵ�͸��� aver�ڵݹ������Ϊǰn�����ĺ�
	if (l == NULL) { 
		//�������β ����ƽ��ֵ ������ �������Ϊ0�򲻳�
		if(num!=0)
		aver /= num; 
		return;
	}
	//�������ֵ
	if (l->data > max) max = l->data;
	//���¸����͵�ǰ "ƽ��ֵ"
	num++; aver += l->data;
	//�ݹ�
	Recursion(l->next, max, num, aver);
}