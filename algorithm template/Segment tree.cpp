#include <iostream>

#define L(u) u << 1													//当前节点的左孩子
#define R(u) u << 1 | 1												//当前节点的右孩子

using namespace std;

const int N = 1e5 + 7;

long long lazy[N << 2];												//lazy标记
long long ans[N << 2];												//区间和值 或 叶子节点值														

int n, m;															//n为输入个数 m为操作次数
int arr[N];															//输入的原始数据
int op, x, y, k;													//操作指示器

void bulid(int u, int l, int r) {									//建立线段树
	if (l == r) {													//搜索到叶子节点 到达递归边缘
		ans[u] = arr[r];											//赋值给叶子节点
		return;
	}
	int mid = (l + r) >> 1;
	bulid(L(u), l, mid);											//建立左儿子
	bulid(R(u), mid + 1, r);										//建立右儿子
	ans[u] = ans[L(u)] + ans[R(u)];									//赋值父亲节点的区间和
}


void pushdown(int u, int l, int r) {								//下放lazy标记
	lazy[L(u)] += lazy[u];											//更新左孩子lazy标记
	lazy[R(u)] += lazy[u];											//更新右孩子lazy标记
	int mid = (l + r) >> 1;
	ans[L(u)] += lazy[u] * (long long)(mid - l + 1);				//更新左孩子ans值
	ans[R(u)] += lazy[u] * (long long)(r - mid);					//更新右孩子ans值
	lazy[u] = 0;													//清除父亲的lazy标记
}


void change(int u, int l, int r, int ll, int rr, long long k) {		//区间修改线段树
	if (l >= ll && r <= rr) {										//如果当前区间被修改区间覆盖
		ans[u] += k * (long long)(r - l + 1);						//当前节点的区间+k*区间内数的数量
		lazy[u] += k;												//打上lazy标记
		return;
	}
	if (lazy[u] != 0)pushdown(u, l, r);								//如果当前节点有lazy标记 下传标记
	int mid = (l + r) >> 1;
	if (mid >= ll) change(L(u), l, mid, ll, rr, k);					//如果要修改的区间与左儿子有交集
	if (mid < rr) change(R(u), mid + 1, r, ll, rr, k);				//如果要修改的区间与右儿子有交集
	ans[u] = ans[L(u)] + ans[R(u)];									//更新父亲节点的区间和
}


long long ask(int u, int l, int r, int ll, int rr) {				//区间查询
	if (l >= ll && r <= rr)return ans[u];							//如果当前区间被修改区间覆盖
	long long t = 0;												//用于合并左右区间查询到的值
	if (lazy[u] != 0)pushdown(u, l, r);								//如果当前节点有lazy标记 下传标记
	int mid = (l + r) >> 1;
	if (mid >= ll)t += ask(L(u), l, mid, ll, rr);					//如果要查询的区间与左儿子有交集
	if (mid < rr)t += ask(R(u), mid + 1, r, ll, rr);				//如果要查询的区间与右儿子有交集
	return t;
}