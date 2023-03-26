#include"Sort.h"
void InsertSort(SqList& S) {
	//ֱ����ԭ�������޸� �ӵ�һ����ʼ ����һ��Ԫ�� �ҵ���Ӧ�ò����λ��
	//�����ߵ�Ԫ�غ���һλ ����λ��ֵΪ��ֵ
	for (int index = 2; index < S.length; index++) {
		if (S.arr[index] >= S.arr[index - 1]) continue;
		S.arr[0] = S.arr[index]; int des = index-1;
		while (S.arr[des] > S.arr[0]) {
			S.arr[des + 1] = S.arr[des];
			des--;
		}
		//������Ԫ��
		S.arr[des+1] = S.arr[0];
	}
}
void BInsertSort(SqList& S) {
	for (int index = 2; index < S.length; index++) {
		if (S.arr[index] >= S.arr[index - 1]) continue;
		int left = 1; int right = index-1;
		int mid = 0;  S.arr[0] = S.arr[index];//�ڱ�ÿ�δ洢Ҫ�����ֵ
		//���ֽ���ʱrightΪҪ�����λ�õ����һ��
		//��Ϊ��left==rightʱ ����ʱ���ֵ��arr[0]�� rightҪ��һ
		//�����˵��Ҫ�����ֵ����arr[left]=arr[right] ��right�ұ�
		//�����������right������Ҫ����λ�õ����
		while (left<=right) {
			mid = (right + left) / 2;
			if (S.arr[mid] > S.arr[0])  right = mid - 1;
			else left = mid + 1;
		}
		for (int j = index; j >= right+1; j--) S.arr[j] = S.arr[j - 1];
		//������Ԫ��
		S.arr[right + 1] = S.arr[0];
	}
}
void ShellSort(SqList& S) {
	//ϣ������ ���ı䲽����ֱ�Ӳ�������
	int step = S.length / 2;
	while (step) {
		for (int index = step+1; index < S.length; index++) {
			if (S.arr[index] >= S.arr[index - step]) continue;
			S.arr[0] = S.arr[index]; int des = index - step;
			while (S.arr[des] > S.arr[0]) {
				S.arr[des + step] = S.arr[des];
				des-=step;
			}
			//������Ԫ��
			S.arr[des + step] = S.arr[0];
		}
		step /= 2;
	}
}
void BubbleSort(SqList& S) {
	for (int i = 0; i < S.length; i++) {
		bool enter = 0;
		for (int j = 0; j < S.length - i - 1; j++) {
			if (S.arr[j] > S.arr[j + 1]) {
				if (!enter) enter = 1;
				int t = S.arr[j]; S.arr[j] = S.arr[j+1]; S.arr[j+1] = t;
			}
		}
		if (!enter)break;
	}
}
void QuickSort(SqList& S) {
	QuickSortMethod(S, 1, S.length - 1);
}
void QuickSortMethod(SqList& S, int start, int end) {//��������
	if (end - start < 1) return;
	int hub = (end + start) / 2; int val = S.arr[hub];
	int l = start; int r = end;
	while (l < r) {
		//��λ��
		while (S.arr[l] < val) l++;
		while (S.arr[r] > val) r--;
		//�ж��Ƿ���Ҫ����λ��
		if (l >= r) break;
		//����λ��
		int t = S.arr[l];
		S.arr[l] = S.arr[r];
		S.arr[r] = t;
		//�������Ŀ��ֵ �ƶ�
		if (S.arr[l] == val) r--;
		if (S.arr[r] == val) l++;
	}
	if (l == r) {
		r--; l++;
	}
	QuickSortMethod(S, start, r);
	QuickSortMethod(S, l, end);
}
void SelectSort(SqList& S) {
	//��i=1��ʼÿ���ҳ���С�� ��i���� 
	for (int i = 1; i < S.length; i++) {
		int min = INT_MAX; int index = 1;
		for (int j = i; j < S.length; j++) {
			if (S.arr[j] < min) {
				index = j;
				min = S.arr[j];
			}
		}
		int t = S.arr[i]; S.arr[i] = S.arr[index];S.arr[index]=t;
	}
}
void MergeSort(SqList& S) {
	int* temp = new int[S.length];
	MergeSortMethod(S, 1, S.length - 1, temp);
}
void MergeSortMethod(SqList& S, int start, int end, int* temp) {
	if (end <= start) return;
	int mid = (end + start) / 2;
	MergeSortMethod(S, start, mid, temp);
	MergeSortMethod(S, mid + 1, end, temp);
	
	int indexOfTemp = start; //ע�����ﲻ��Ϊ1 ҪΪstart
	int l = start; int r = mid + 1;
	//����С˳��ϲ���temp
	while (l <= mid && r <= end) {
		if (S.arr[l] < S.arr[r]) temp[indexOfTemp++] = S.arr[l++];
		else temp[indexOfTemp++] = S.arr[r++];
	}
	while (l <= mid) temp[indexOfTemp++] = S.arr[l++];
	while (r <= end) temp[indexOfTemp++] = S.arr[r++];
	//����ԭ����
	for (int i = start; i <= end; i++) S.arr[i] = temp[i];
}
void HeapAdjust(SqList& S,int s,int m) {
	//���жѵ��� ����r[s+1...m]�Ѿ��Ƕ� ��r[s...m]����Ϊ��r[s]Ϊ���Ĵ����
	int res = S.arr[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && S.arr[j] < S.arr[j + 1])j++;
		if (S.arr[j] <= res) break;
		//��λj��ֵ���Ľ�� �뵱ǰ���ڵ�s ��j����s ����j=s Ϊ��һ�εĸ��ڵ�
		//���ֹͣʱ ����ǰ��������ֵres��������s��λ�� ��ԭ
		S.arr[s] = S.arr[j]; s = j;
	}
	S.arr[s] = res;
}
void CreateHeap(SqList& S) {//ѭ�����з�Ҷ�ӽ�� ���������
	for (int i = (S.length - 1) / 2; i > 0; i--) HeapAdjust(S, i, S.length-1);
}
void HeapSort(SqList& S) {
	CreateHeap(S);//���ȴ��������
	//ÿ�������Ľ�������㽻��
	for (int i = S.length - 1; i > 1; i--) { //ֻʣһ��ʱ��������
		int min = S.arr[1];
		S.arr[1] = S.arr[i];
		S.arr[i] = min;
		//������Ϻ� ��1��i-1���µ���Ϊ�����
		HeapAdjust(S, 1, i-1 );
	}
}
void showArr(SqList S) {
	for (int i = 1; i < S.length; i++) {
		cout << S.arr[i] << " ";
	}
	cout << "\n";
}
void showArrp(int* arr,int length) {
	for (int i = 1; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}