#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"List.h"
int main_list() {
	LinkedList l1 = getList_R(4);
	int max = 0, num = 0, aver = 0;
	RecurPre(l1, max, num, aver);
	showList(l1);
	cout << max << " " << num << " " << aver;
	return 0;
}