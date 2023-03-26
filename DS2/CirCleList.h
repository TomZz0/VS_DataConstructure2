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
void InitCList(CLinkedList& l); //初始化循环队列
CLinkedList InitCList();//获取初始化后的循环队列
bool isEmpty(CLQueue cq);//判断队列是否为空
void EnterQueue(CLQueue& cq, int val);//入队操作 从尾部加入
void DeQueue(CLQueue& cq);//出队操作 从头部出队
void showCLQueue(CLQueue cq);//循环打印队列
void SetEmpty(CLQueue& cq);//置空队列