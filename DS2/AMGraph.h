#include"status.h"
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
//ͼ���ڽӾ���Ĵ洢��ʾ
#define MaxInt 32767  //��ʾ�����
#define MVNum 100	 //���洢�Ķ������
typedef char VerTexType; //����Ϊchar����
typedef int ArcType;    //�ߵ�ȨֵΪ����
typedef struct {
	VerTexType vexs[MVNum]; //���㼯
	ArcType arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;     //ͼ�Ķ������ͱ���
}AMGraph;
//������
Status CreateUDN(AMGraph& G);
int LocateVex(AMGraph G, char v1);