#define MAXSIZE 1000
#include<iostream>
using namespace std;
typedef struct SqList {
	int* arr; //�����±��1��ʼ 0λ�ò���
	int length;
}SqList;
void InsertSort(SqList& S);//ֱ�Ӳ�������
void BInsertSort(SqList& S);//�۰��������
void ShellSort(SqList& S);//ϣ������
void BubbleSort(SqList& S);//ð������
void QuickSort(SqList& S);//��������
void QuickSortMethod(SqList& S, int start, int end);//���ŵݹ鷽��
void SelectSort(SqList& S);//ѡ������
void MergeSort(SqList& S);//�鲢����
void MergeSortMethod(SqList& S, int start, int end,int*temp);//�鲢�ݹ鷽��
void HeapAdjust(SqList& S,int s,int m);//�ѵ���
void CreateHeap(SqList& S);//���������
void HeapSort(SqList& S);//������
void showArr(SqList S);//�����ӡ
void showArrp(int* arr, int length);