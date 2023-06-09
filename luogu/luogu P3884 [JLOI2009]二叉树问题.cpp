#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 107;

/*
	Âå¹ÈP3884 [JLOI2009]¶þ²æÊ÷ÎÊÌâ
	https://www.luogu.com.cn/problem/P3884
*/

struct Tree {
	int parent;
	int dig;
	vector <int> son;
}tree[N];

int width[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].son.push_back(v);
		tree[v].parent = u;
	}
	queue <int> q;
	q.push(1);
	tree[1].dig = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int v : tree[t].son) {
			q.push(v);
			tree[v].dig = tree[t].dig + 1;
			width[tree[v].dig]++;
		}
	}
	int ans_dig = 0, ans_width = 0;
	for (int i = 1; i <= n; i++)ans_dig = max(ans_dig, tree[i].dig), ans_width = max(ans_width, width[i]);
	int x, y;
	cin >> x >> y;
	int ans = 0;
	while (x != y) {
		if (tree[x].dig > tree[y].dig) {
			ans += 2;
			x = tree[x].parent;
		}
		else if (tree[x].dig < tree[y].dig) {
			ans++;
			y = tree[y].parent;
		}
		else {
			ans += 3;
			x = tree[x].parent;
			y = tree[y].parent;
		}
	}
	cout << ans_dig << "\n" << ans_width << "\n" << ans;
	return 0;
}