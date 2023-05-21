#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <memory.h>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define L(u) u << 1
#define R(u) u << 1 | 1

using namespace std;

/*
    luogu P1113 杂物
    https://www.luogu.com.cn/problem/P1113
*/

typedef long long llint;
typedef pair<int, int> PII;

static const int N = 1e4 + 3;
int vis[N];
int len[N];
int in[N];
vector <int> E[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> len[i];
        cin >> v;
        while (v) {
            in[i]++;                            //有多少前置工作就有多少条入度
            E[v].push_back(u);			        //v是u的前置工作
            cin >> v;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
		if (!in[i]) q.push(i);                  //入度为0的点入队
	}
    while (!q.empty()) {
		int u = q.front();
		q.pop();
        vis[u] += len[u];                       //更新最早完成时间
        for (int v : E[u]) {
			vis[v] = max(vis[v], vis[u]);       //更新最早完成时间
			if (--in[v] == 0) q.push(v);        //入度为0的点入队
		}
	}
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, vis[i]);
	}
    cout << ans;
	return 0;
}