#include"Sort.h"
#include<iostream>
using namespace std;
int main_sort() {
	int arr[15] = {0, 49,38,65,97,76,13,27,49,7,4,67,90,58,21};
	SqList S{};
	S.arr = arr;
	S.length = 15;
	showArr(S);
	HeapSort(S);
	showArr(S);
	return 0;
}