#include<stdio.h>
#include<malloc.h>
//.c�ļ� ʵ��.h�ļ��������ĺ���
struct SeqStack_Char {
	int MAXNUM;  //���洢����
	int t;		//��ǰջ��λ��
	char* s;
};   //PSeqStackָһ��ջ�ĵ�ַ
typedef struct SeqStack_Char* CSeqStack;

CSeqStack createEmptyStackChar_seq(int m);
int isEmptyStack_seq(CSeqStack p);
void push_seq(CSeqStack p, char x);
void pop_seq(CSeqStack p);
char top_seq(CSeqStack p);
