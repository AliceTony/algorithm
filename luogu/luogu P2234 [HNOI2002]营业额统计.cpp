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
	P2234 [HNOI2002]营业额统计
	https://www.luogu.com.cn/problem/P2234
*/

typedef pair<int, int> PII;
const int N = 2e5 + 10, M = 2e5;
set <int> arr;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int sum;
	cin >> sum;
	arr.insert(sum);
	for (int i = 1; i < n; i++) {
		int temp, num = INT_MAX;
		cin >> temp;
		auto it = arr.lower_bound(temp);
		if (it != arr.end()) num = *it - temp;
		if (it != arr.begin()) {
			it--;
			num = min(num, temp - *it);
		}
		sum += num;
		arr.insert(temp);
	}
	cout << sum;
	return 0;
}