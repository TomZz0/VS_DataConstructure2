#include"ALGraph.h"
Status CreateUDG(ALGraph& G) {
	cout << "请输入顶点数和边数:";
	cin >> G.vexnum; cin >> G.arcnum;//输入图的顶点数和边数
	for (int i = 0; i < G.vexnum; i++) { //输入各点信息 构造顶点集
		cout << "请输入第" << i + 1 << "个顶点的名称";
		cin >> G.vertices[i].VexName;
		G.vertices[i].firstarc = NULL;//暂时无边 置空
	}
	for (int i = 0; i < G.arcnum; i++) //输入各边信息 构造边集 头插法
	{
		cout << "请输入边的两个顶点 用单个字符表示:";
		string v1, v2;cin >> v1 >> v2; //输入边的两个顶点名称
		int v1pos = LocateVex(G, v1);//获取顶点位置
		int v2pos = LocateVex(G, v2);
		ArcNode* p = new ArcNode;  //创建边节点 插入到v1的边集
		p->adjvex = v2pos;        //邻接点的位置 或者叫序号
		p->nextarc = G.vertices[v1pos].firstarc; G.vertices[v1pos].firstarc = p;
		ArcNode* q = new ArcNode;//将边插入到v2的边集
		q->adjvex = v1pos;
		q->nextarc = G.vertices[v2pos].firstarc; G.vertices[v2pos].firstarc = q;
	}
	return OK;
}

int LocateVex(ALGraph G, string vex) {
	for (int i = 0; i <G.vexnum; i++)
	{
		if (G.vertices[i].VexName._Equal(vex)) return i;
	}
	return -1;
}
