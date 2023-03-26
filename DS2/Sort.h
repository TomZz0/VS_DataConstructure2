#define MAXSIZE 1000
#include<iostream>
using namespace std;
typedef struct SqList {
	int* arr; //数组下标从1开始 0位置不用
	int length;
}SqList;
void InsertSort(SqList& S);//直接插入排序
void BInsertSort(SqList& S);//折半插入排序
void ShellSort(SqList& S);//希尔排序
void BubbleSort(SqList& S);//冒泡排序
void QuickSort(SqList& S);//快速排序
void QuickSortMethod(SqList& S, int start, int end);//快排递归方法
void SelectSort(SqList& S);//选择排序
void MergeSort(SqList& S);//归并排序
void MergeSortMethod(SqList& S, int start, int end,int*temp);//归并递归方法
void HeapAdjust(SqList& S,int s,int m);//堆调整
void CreateHeap(SqList& S);//创建大根堆
void HeapSort(SqList& S);//堆排序
void showArr(SqList S);//数组打印
void showArrp(int* arr, int length);