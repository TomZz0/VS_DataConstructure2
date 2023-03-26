#include"CirCleList.h"
int main_cl() {
	CLQueue cq{};
	cq.rear = InitCList();
	EnterQueue(cq, 1);
	EnterQueue(cq, 2);
	EnterQueue(cq, 3);
	EnterQueue(cq, 4);
	EnterQueue(cq, 5);
	EnterQueue(cq, 6);
	showCLQueue(cq);
	SetEmpty(cq);
	showCLQueue(cq);

	return 0;
}