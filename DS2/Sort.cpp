#include"Sort.h"
void InsertSort(SqList& S) {
	//直接在原数组上修改 从第一个开始 加入一个元素 找到其应该插入的位置
	//将其后边的元素后移一位 将次位赋值为新值
	for (int index = 2; index < S.length; index++) {
		if (S.arr[index] >= S.arr[index - 1]) continue;
		S.arr[0] = S.arr[index]; int des = index-1;
		while (S.arr[des] > S.arr[0]) {
			S.arr[des + 1] = S.arr[des];
			des--;
		}
		//放置新元素
		S.arr[des+1] = S.arr[0];
	}
}
void BInsertSort(SqList& S) {
	for (int index = 2; index < S.length; index++) {
		if (S.arr[index] >= S.arr[index - 1]) continue;
		int left = 1; int right = index-1;
		int mid = 0;  S.arr[0] = S.arr[index];//哨兵每次存储要排序的值
		//二分结束时right为要插入的位置的左边一个
		//因为当left==right时 若此时这个值比arr[0]大 right要减一
		//否则就说明要插入的值大于arr[left]=arr[right] 即right右边
		//所以无论如何right都是在要插入位置的左边
		while (left<=right) {
			mid = (right + left) / 2;
			if (S.arr[mid] > S.arr[0])  right = mid - 1;
			else left = mid + 1;
		}
		for (int j = index; j >= right+1; j--) S.arr[j] = S.arr[j - 1];
		//放置新元素
		S.arr[right + 1] = S.arr[0];
	}
}
void ShellSort(SqList& S) {
	//希尔排序 即改变步长的直接插入排序
	int step = S.length / 2;
	while (step) {
		for (int index = step+1; index < S.length; index++) {
			if (S.arr[index] >= S.arr[index - step]) continue;
			S.arr[0] = S.arr[index]; int des = index - step;
			while (S.arr[des] > S.arr[0]) {
				S.arr[des + step] = S.arr[des];
				des-=step;
			}
			//放置新元素
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
void QuickSortMethod(SqList& S, int start, int end) {//快速排序
	if (end - start < 1) return;
	int hub = (end + start) / 2; int val = S.arr[hub];
	int l = start; int r = end;
	while (l < r) {
		//找位置
		while (S.arr[l] < val) l++;
		while (S.arr[r] > val) r--;
		//判断是否需要交换位置
		if (l >= r) break;
		//交换位置
		int t = S.arr[l];
		S.arr[l] = S.arr[r];
		S.arr[r] = t;
		//如果等于目标值 移动
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
	//从i=1开始每次找出最小的 与i交换 
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
	
	int indexOfTemp = start; //注意这里不能为1 要为start
	int l = start; int r = mid + 1;
	//按大小顺序合并到temp
	while (l <= mid && r <= end) {
		if (S.arr[l] < S.arr[r]) temp[indexOfTemp++] = S.arr[l++];
		else temp[indexOfTemp++] = S.arr[r++];
	}
	while (l <= mid) temp[indexOfTemp++] = S.arr[l++];
	while (r <= end) temp[indexOfTemp++] = S.arr[r++];
	//更新原数组
	for (int i = start; i <= end; i++) S.arr[i] = temp[i];
}
void HeapAdjust(SqList& S,int s,int m) {
	//进行堆调整 假设r[s+1...m]已经是堆 将r[s...m]调整为以r[s]为根的大根堆
	int res = S.arr[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && S.arr[j] < S.arr[j + 1])j++;
		if (S.arr[j] <= res) break;
		//定位j到值最大的结点 与当前根节点s 将j覆盖s 在让j=s 为下一次的根节点
		//最后停止时 将提前保存的最大值res覆盖最后的s的位置 复原
		S.arr[s] = S.arr[j]; s = j;
	}
	S.arr[s] = res;
}
void CreateHeap(SqList& S) {//循环所有非叶子结点 创建大根堆
	for (int i = (S.length - 1) / 2; i > 0; i--) HeapAdjust(S, i, S.length-1);
}
void HeapSort(SqList& S) {
	CreateHeap(S);//首先创建大根堆
	//每次让最后的结点与根结点交换
	for (int i = S.length - 1; i > 1; i--) { //只剩一个时不用排序
		int min = S.arr[1];
		S.arr[1] = S.arr[i];
		S.arr[i] = min;
		//交换完毕后 将1到i-1重新调整为大根堆
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