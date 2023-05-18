#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define L(u) u << 1
#define R(u) u << 1 | 1

using namespace std;

typedef long long llint;
typedef pair<int, int> PII;

/*
    luguo P3916 图的遍历
    https://www.luogu.com.cn/problem/P3916
*/

const int N = 1e5 + 7;
int n, m;
int u, v;
vector<int> e[N];

int vis[N];
int check[N];

int map_serch(int x) {
    if (vis[x]) return vis[x];                      //如果已经查阅过了 返回
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int t = q.front();
        q.pop();
        if (vis[t]) continue;
        vis[t] = x;                                 //更新当前值
        for (int i : e[t]) {                        //遍历所有的边
            if (vis[i]) continue;
            q.push(i);
        }
    }
    return vis[x];                                  
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v >> u;          
        e[u].push_back(v);                          //方向建边
    }
    for (int i = n; i >= 1; i--) map_serch(i);
    for (int i = 1; i <= n; i++)cout << map_serch(i) << " ";
    return 0;
}

