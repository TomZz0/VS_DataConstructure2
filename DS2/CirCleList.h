#include<stdio.h>
#include"status.h"
#include <iostream>
using namespace std;
typedef struct CLNode {
	int data;
	struct CLNode* next;
}CLNode, * CLinkedList;
typedef struct CLQueue {
	CLinkedList rear;
}CLQueue;
void InitCList(CLinkedList& l); //��ʼ��ѭ������
CLinkedList InitCList();//��ȡ��ʼ�����ѭ������
bool isEmpty(CLQueue cq);//�ж϶����Ƿ�Ϊ��
void EnterQueue(CLQueue& cq, int val);//��Ӳ��� ��β������
void DeQueue(CLQueue& cq);//���Ӳ��� ��ͷ������
void showCLQueue(CLQueue cq);//ѭ����ӡ����
void SetEmpty(CLQueue& cq);//�ÿն���