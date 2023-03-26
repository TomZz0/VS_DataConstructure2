#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"CharStack.h"
int isHuiWenString(char* s, int length);
int main_huiwen() {
	char* s = "abba"; 
	if (isHuiWenString(s, 4)) {
		printf("字符串%s是回文串", s);
	}
	else {
		printf("字符串%s不是回文串", s);
	}
	return 0;
}
int isHuiWenString(char* s, int length) {
	int len = length % 2 == 0 ? length / 2 : length / 2 + 1;
	CSeqStack stack =  createEmptyStackChar_seq(len);
	for (int i = 0; i < len; i++) {
		push_seq(stack, s[i]);
	}
	for (int i = length%2==0?len:len-1; i < length; i++) {
		if (s[i] != top_seq(stack)) return 0;
		pop_seq(stack);
	}
	return 1;
}