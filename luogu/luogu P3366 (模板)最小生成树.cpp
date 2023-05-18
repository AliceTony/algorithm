#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


class Kruskal {
private:
	/*
		存放无向边,对cost进行排序
	*/
	struct Edge {
		int u;													//左端点
		int v;													//右端点
		int cost;												//消耗值
		Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
		Edge() :u(0), v(0), cost(0) {}
		bool operator > (const Edge b) const {
			return cost > b.cost;
		}
		bool operator < (const Edge b) const {
			return cost < b.cost;
		}
	};
	int n;														//点的数量
	vector <int> father;										//祖父母
	vector<Edge> edge;											//存放边
public:

	//初始化一共拥有多少点 与 拥有多少边
	Kruskal(int x, int e) {
		n = x;
		father.resize(n + 1);
		edge.reserve(e);
	}

	/*
		添加边
	*/
	void add_edge(int u, int v, int cost) {
		edge.push_back({ u , v , cost });
	}

	/*
		寻找对应节点的祖先
	*/
	int findfather(int x) {
		int a = x;
		while (x != father[x]) x = father[x];
		//路径压缩
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
		for (int i = 1; i <= n; i++)father[i] = i;					//初始化每个节点的祖父母为本身
		sort(edge.begin(), edge.end());								//对边权进行排序
		for (Edge i : edge) {
			int u = i.u, v = i.v;
			int fu = findfather(u);									//确认左端点的祖父母
			int fv = findfather(v);									//确认右端点的祖父母
			if (fu != fv) {											//如果祖父母不同,判定为 没有联通 加入集合
				father[fu] = fv;									//更新祖父母
				res += i.cost;
				mark++;
				if (mark == n - 1)break;							//已经构建好生成树 退出
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
