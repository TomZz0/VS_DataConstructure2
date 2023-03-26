#include<stdio.h>
#include"status.h"
#include <iostream>
using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkedList;

//函数区
void InitList(LinkedList& l);
LinkedList InitList();
Status GetElem(LinkedList l, int i, int& e);
int GetElem(LinkedList l, int i);
int LocateElem_pos(LinkedList l, int e);
LNode* LocateElem_ele(LinkedList l, int e);
Status ListInsert(LinkedList& l, int i, int e);
Status ListDeleteByIndex(LinkedList& l, int i);
void ListDeleteByValue(LinkedList& l, int i);
void CreateList_H(LinkedList& l, int n);
void CreateList_R(LinkedList& l, int n);
LinkedList getList_H(int n);
LinkedList getList_R(int n);
void insert_front(LinkedList& l, int e);
void insert_back(LinkedList& l, int e);
bool contain(LinkedList l, int e);
void showList(LinkedList l);
void MergeList(LinkedList& l1, LinkedList l2);
void MergeListless(LinkedList&l1,LinkedList&l2);
LinkedList Merge_of_seqList(LinkedList& l1, LinkedList& l2);
void deleteList(LinkedList l);
LNode* getMax(LinkedList list);
LinkedList reverse1(LinkedList& list);
void reverseNode1(LNode* pre, LNode* cur);

void reverse2(LinkedList& list);
LNode* reverseNode2(LNode* list, LNode* pre, LNode* cur);
void divideListByPN(LinkedList& l1, LinkedList& A, LinkedList& B);
void RecurPre(LinkedList l, int& max, int& num, int& aver);
void Recursion(LinkedList l,int&max,int&num,int&aver);// 递归求链表的最大整数 节点个数和平均值