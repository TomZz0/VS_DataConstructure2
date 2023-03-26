#include"AMGraph.h"
Status CreateUDN(AMGraph& G) {
	//�����ڽӾ����ʾ������������G

	cin >> G.vexnum; cin >> G.arcnum; //���붥���������ܱ���
	for (int i = 0; i < G.vexnum; i++) cin >> G.vexs[i];//��������Ϣ
	for (int i = 0; i < G.vexnum; i++) //��ʼ���ڽӾ��� ����Ϊ�����
		for (int j = 0; j < G.arcnum; j++)
			G.arcs[i][j] = MaxInt;
	for (int k = 0; k < G.arcnum; k++) {//�����ڽӾ���
		char v1, v2; int w;  //���붥���֮��ߵ�Ȩֵ
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);//��������������ڽӱ��е�λ��
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