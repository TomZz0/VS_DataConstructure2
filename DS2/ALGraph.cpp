#include"ALGraph.h"
Status CreateUDG(ALGraph& G) {
	cout << "�����붥�����ͱ���:";
	cin >> G.vexnum; cin >> G.arcnum;//����ͼ�Ķ������ͱ���
	for (int i = 0; i < G.vexnum; i++) { //���������Ϣ ���춥�㼯
		cout << "�������" << i + 1 << "�����������";
		cin >> G.vertices[i].VexName;
		G.vertices[i].firstarc = NULL;//��ʱ�ޱ� �ÿ�
	}
	for (int i = 0; i < G.arcnum; i++) //���������Ϣ ����߼� ͷ�巨
	{
		cout << "������ߵ��������� �õ����ַ���ʾ:";
		string v1, v2;cin >> v1 >> v2; //����ߵ�������������
		int v1pos = LocateVex(G, v1);//��ȡ����λ��
		int v2pos = LocateVex(G, v2);
		ArcNode* p = new ArcNode;  //�����߽ڵ� ���뵽v1�ı߼�
		p->adjvex = v2pos;        //�ڽӵ��λ�� ���߽����
		p->nextarc = G.vertices[v1pos].firstarc; G.vertices[v1pos].firstarc = p;
		ArcNode* q = new ArcNode;//���߲��뵽v2�ı߼�
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
