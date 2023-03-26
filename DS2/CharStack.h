#include<stdio.h>
#include<malloc.h>
//.c文件 实现.h文件中声明的函数
struct SeqStack_Char {
	int MAXNUM;  //最大存储数量
	int t;		//当前栈顶位置
	char* s;
};   //PSeqStack指一个栈的地址
typedef struct SeqStack_Char* CSeqStack;

CSeqStack createEmptyStackChar_seq(int m);
int isEmptyStack_seq(CSeqStack p);
void push_seq(CSeqStack p, char x);
void pop_seq(CSeqStack p);
char top_seq(CSeqStack p);
