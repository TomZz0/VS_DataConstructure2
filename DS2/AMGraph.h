#include"status.h"
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
//图的邻接矩阵的存储表示
#define MaxInt 32767  //表示无穷大
#define MVNum 100	 //最多存储的顶点个数
typedef char VerTexType; //顶点为char类型
typedef int ArcType;    //边的权值为整型
typedef struct {
	VerTexType vexs[MVNum]; //顶点集
	ArcType arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;     //图的顶点数和边数
}AMGraph;
//方法区
Status CreateUDN(AMGraph& G);
int LocateVex(AMGraph G, char v1);