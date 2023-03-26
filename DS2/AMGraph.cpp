#include"AMGraph.h"
Status CreateUDN(AMGraph& G) {
	//采用邻接矩阵表示法创建无向网G

	cin >> G.vexnum; cin >> G.arcnum; //输入顶点总数和总边数
	for (int i = 0; i < G.vexnum; i++) cin >> G.vexs[i];//输入点的信息
	for (int i = 0; i < G.vexnum; i++) //初始化邻接矩阵 距离为无穷大
		for (int j = 0; j < G.arcnum; j++)
			G.arcs[i][j] = MaxInt;
	for (int k = 0; k < G.arcnum; k++) {//构建邻接矩阵
		char v1, v2; int w;  //输入顶点和之间边的权值
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);//获得两个顶点在邻接表中的位置
		int j = LocateVex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = w;
	}
	return OK;
}
int LocateVex(AMGraph G, char v1) {
	for (int i = 0; i < G.vexnum; i++) {
		if (v1 == G.vexs[i]) return i;
	}
}