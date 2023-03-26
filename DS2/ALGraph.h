#include<iostream>
#include<string.h>
#include"status.h"
using namespace std;
#define MVNum 100 //最大顶点数

typedef struct ArcNode { //边结点
	int adjvex;//边所指向的顶点的位置 已知起始点 这个应该是终点
	struct ArcNode* nextarc;//指向所属起始点的下一条边的指针
	int weigh;   //边的权值
} ArcNode;
typedef struct VNode { //顶点信息
	string VexName;   //顶点信息
	ArcNode* firstarc; //指向依赖这个顶点的第一条边的指针
}VNode,AdjList[MVNum]; //AdjList表示邻接表类型
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//图的当前定点数和边数
}ALGraph;
Status CreateUDG(ALGraph& G); //创建无向图
int LocateVex(ALGraph G, string vex);//通过顶点名得到顶点在顶点集中的位置并返回 -1
