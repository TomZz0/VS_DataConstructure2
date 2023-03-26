#include"CharStack.h"
CSeqStack createEmptyStackChar_seq(int m) {
	//使用malloc分配空间 这时s为一个数组
	CSeqStack stack = (CSeqStack)malloc(sizeof(struct SeqStack_Char));
	if (stack != NULL) {
		stack->s = (char*)malloc(sizeof(char) * m);
		if (stack->s) {
			stack->MAXNUM = m;
			stack->t = -1;
			return stack;
		}
		else {
			free(stack);
		}
	}
	printf("分配失败");
	return NULL;

}
int isEmptyStack_seq(CSeqStack p) {
	return p->t == -1 ? 1 : 0;
}
void push_seq(CSeqStack p, char x) {
	//如果栈已满 输出OverFlow 返回
	if (p->t >= p->MAXNUM - 1) {
		printf("OverFlow!");
		return;
	}
	//令栈顶指针右移 赋值
	(p->t)++;
	p->s[p->t] = x;
}
void pop_seq(CSeqStack p) {
	//删除栈顶元素
	if (p->t == -1) {
		printf("UnderFlow!");
		return;
	}
	(p->t)--;
}
char top_seq(CSeqStack p) {
	if (p->t == -1) {
		printf("Empty Stack!");
		return 0;
	}
	return p->s[p->t];
}
