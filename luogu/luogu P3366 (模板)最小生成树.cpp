#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


class Kruskal {
private:
	/*
		��������,��cost��������
	*/
	struct Edge {
		int u;													//��˵�
		int v;													//�Ҷ˵�
		int cost;												//����ֵ
		Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
		Edge() :u(0), v(0), cost(0) {}
		bool operator > (const Edge b) const {
			return cost > b.cost;
		}
		bool operator < (const Edge b) const {
			return cost < b.cost;
		}
	};
	int n;														//�������
	vector <int> father;										//�游ĸ
	vector<Edge> edge;											//��ű�
public:

	//��ʼ��һ��ӵ�ж��ٵ� �� ӵ�ж��ٱ�
	Kruskal(int x, int e) {
		n = x;
		father.resize(n + 1);
		edge.reserve(e);
	}

	/*
		��ӱ�
	*/
	void add_edge(int u, int v, int cost) {
		edge.push_back({ u , v , cost });
	}

	/*
		Ѱ�Ҷ�Ӧ�ڵ������
	*/
	int findfather(int x) {
		int a = x;
		while (x != father[x]) x = father[x];
		//·��ѹ��
		while (a != x) {
			int z = a;
			a = father[a];
			father[z] = x;
		}
		return x;
	}

	int kruskal() {
		int mark = 0;
		int res = 0;
		for (int i = 1; i <= n; i++)father[i] = i;					//��ʼ��ÿ���ڵ���游ĸΪ����
		sort(edge.begin(), edge.end());								//�Ա�Ȩ��������
		for (Edge i : edge) {
			int u = i.u, v = i.v;
			int fu = findfather(u);									//ȷ����˵���游ĸ
			int fv = findfather(v);									//ȷ���Ҷ˵���游ĸ
			if (fu != fv) {											//����游ĸ��ͬ,�ж�Ϊ û����ͨ ���뼯��
				father[fu] = fv;									//�����游ĸ
				res += i.cost;
				mark++;
				if (mark == n - 1)break;							//�Ѿ������������� �˳�
			}
		}
		if (mark != n - 1) return 0;
		return res;
	}
};


int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	Kruskal* kruskal = new Kruskal(n, m);
	int u, v, cost;
	for (int i = 0; i < m; i++) cin >> u >> v >> cost, kruskal->add_edge(u, v, cost);
	int res = kruskal->kruskal();
	if (res) cout << res;
	else cout << "orz";
	return 0;
}
