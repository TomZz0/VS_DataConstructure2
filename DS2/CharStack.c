#include"CharStack.h"
CSeqStack createEmptyStackChar_seq(int m) {
	//ʹ��malloc����ռ� ��ʱsΪһ������
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
	printf("����ʧ��");
	return NULL;

}
int isEmptyStack_seq(CSeqStack p) {
	return p->t == -1 ? 1 : 0;
}
void push_seq(CSeqStack p, char x) {
	//���ջ���� ���OverFlow ����
	if (p->t >= p->MAXNUM - 1) {
		printf("OverFlow!");
		return;
	}
	//��ջ��ָ������ ��ֵ
	(p->t)++;
	p->s[p->t] = x;
}
void pop_seq(CSeqStack p) {
	//ɾ��ջ��Ԫ��
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
