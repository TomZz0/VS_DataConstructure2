#include<iostream>
#include<string.h>
#include"status.h"
using namespace std;
#define MVNum 100 //��󶥵���

typedef struct ArcNode { //�߽��
	int adjvex;//����ָ��Ķ����λ�� ��֪��ʼ�� ���Ӧ�����յ�
	struct ArcNode* nextarc;//ָ��������ʼ�����һ���ߵ�ָ��
	int weigh;   //�ߵ�Ȩֵ
} ArcNode;
typedef struct VNode { //������Ϣ
	string VexName;   //������Ϣ
	ArcNode* firstarc; //ָ�������������ĵ�һ���ߵ�ָ��
}VNode,AdjList[MVNum]; //AdjList��ʾ�ڽӱ�����
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;
Status CreateUDG(ALGraph& G); //��������ͼ
int LocateVex(ALGraph G, string vex);//ͨ���������õ������ڶ��㼯�е�λ�ò����� -1
