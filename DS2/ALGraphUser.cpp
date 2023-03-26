#include"ALGraph.h"
bool visited[MVNum];//访问数组
bool finishDFS(ALGraph G);
void DFS(ALGraph G, int v);//从顶点v开始深度优先遍历无向图
void BFS(ALGraph G, int v);//从顶点v开始广度优先遍历无向图
int main_ALG() {
	ALGraph G; CreateUDG(G);
	for (int i = 0; i < G.vexnum; i++) visited[i] = 0;
	DFS(G, 0);
	cout << "\n";
	for (int i = 0; i < G.vexnum; i++) visited[i] = 0;
	BFS(G, 0);
	return 0;

}
void DFS(ALGraph G, int v) {
	cout << G.vertices[v].VexName << "->";
	visited[v] = 1;
	ArcNode* cur = G.vertices[v].firstarc;
	while (!finishDFS(G)&&cur != NULL) {
		if (!visited[cur->adjvex]) DFS(G, cur->adjvex);
		cur = cur->nextarc;
	}
}
void BFS(ALGraph G, int v) {
	
	for (int i = 0; i < G.vexnum&&!finishDFS(G); i++) {
		VNode curV = G.vertices[i];
		cout << G.vertices[i].VexName << "->";
		visited[i] = 1;
		ArcNode* cur = curV.firstarc;
		while (cur != NULL) {
			if (!visited[cur->adjvex]) {
				cout << G.vertices[cur->adjvex].VexName << "->";
				visited[cur->adjvex] = 1;
			}
			cur = cur->nextarc;
		}
	}
}
bool finishDFS(ALGraph G) {
	for (int i = 0; i < G.vexnum; i++) if (!visited[i]) return 0;
	return 1;
}