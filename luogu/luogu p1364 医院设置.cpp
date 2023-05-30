#include <iostream>
#include <memory.h>
#include <string>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define L(u) u << 1														//当前节点的左孩子
#define R(u) u << 1 | 1													//当前节点的右孩子

/*
	P1364 医院设置
	https://www.luogu.com.cn/problem/P1364
*/

typedef pair<int, int> PII;
const int N = 100 + 7;
bool vis[N];
struct TreeNode {
	int father;
	int l, r;
	int val;
}tree[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r, val;
		cin >> val >> l >> r;
		tree[i].l = l;
		tree[i].r = r;
		tree[i].val = val;
		if (l) tree[l].father = i;
		if (r) tree[r].father = i;
	}
	int ans = INT_MAX;

	for (int i = 1; i <= n; i++) {
		queue <PII> q;
		memset(vis, 0, sizeof(vis));
		q.push({ i , 0 });
		vis[i] = 1;
		int sum = 0;
		while (!q.empty()) {
			PII u = q.front();
			q.pop();
			sum += tree[u.first].val * u.second;
			if (tree[u.first].l && !vis[tree[u.first].l]) vis[tree[u.first].l] = 1, q.push({ tree[u.first].l, u.second + 1 });
			if (tree[u.first].r && !vis[tree[u.first].r]) vis[tree[u.first].r] = 1, q.push({ tree[u.first].r, u.second + 1 });
			if (tree[u.first].father && !vis[tree[u.first].father]) vis[tree[u.first].father] = 1, q.push({ tree[u.first].father, u.second + 1 });
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}