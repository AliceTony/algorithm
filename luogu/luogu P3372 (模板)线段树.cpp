#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
	luogu P3372 (ģ��)�߶���
	https://www.luogu.com.cn/problem/P3372
*/

#define L(u) u << 1														//��ǰ�ڵ������
#define R(u) u << 1 | 1													//��ǰ�ڵ���Һ���
class Segment_tree {
private:
	int n;																//ԭʼ���ݳ���
	vector<long long> lazy;												//lazy���
	vector<long long> ans;												//�����ֵ �� Ҷ�ӽڵ�ֵ														
	vector <int> arr;													//�����ԭʼ����

	void bulid(int u, int l, int r) {									//�����߶���
		if (l == r) {													//������Ҷ�ӽڵ� ����ݹ��Ե
			ans[u] = arr[r];											//��ֵ��Ҷ�ӽڵ�
			return;
		}
		int mid = (l + r) >> 1;
		bulid(L(u), l, mid);											//���������
		bulid(R(u), mid + 1, r);										//�����Ҷ���
		ans[u] = ans[L(u)] + ans[R(u)];									//��ֵ���׽ڵ�������
	}

	void pushdown(int u, int l, int r) {								//�·�lazy���
		lazy[L(u)] += lazy[u];											//��������lazy���
		lazy[R(u)] += lazy[u];											//�����Һ���lazy���
		int mid = (l + r) >> 1;
		ans[L(u)] += lazy[u] * (long long)(mid - l + 1);				//��������ansֵ
		ans[R(u)] += lazy[u] * (long long)(r - mid);					//�����Һ���ansֵ
		lazy[u] = 0;													//������׵�lazy���
	}

public:

	Segment_tree(int len, vector <int>& nums) {
		n = len;
		lazy.resize((n << 2) + 1);										//��ʼlazy������
		ans.resize((n << 2) + 1);										//��ʼ��ans����
		arr = move(nums);												//��nums��ֵ��arr
		bulid(1, 1, n);													//�����߶���
	}

	void change(int u, int l, int r, int ll, int rr, long long k) {		//�����޸��߶���
		if (l >= ll && r <= rr) {										//�����ǰ���䱻�޸����串��
			ans[u] += k * (long long)(r - l + 1);						//��ǰ�ڵ������+k*��������������
			lazy[u] += k;												//����lazy���
			return;
		}
		if (lazy[u] != 0)pushdown(u, l, r);								//�����ǰ�ڵ���lazy��� �´����
		int mid = (l + r) >> 1;
		if (mid >= ll) change(L(u), l, mid, ll, rr, k);					//���Ҫ�޸ĵ�������������н���
		if (mid < rr) change(R(u), mid + 1, r, ll, rr, k);				//���Ҫ�޸ĵ��������Ҷ����н���
		ans[u] = ans[L(u)] + ans[R(u)];									//���¸��׽ڵ�������
	}

	long long ask(int u, int l, int r, int ll, int rr) {				//�����ѯ
		if (l >= ll && r <= rr)return ans[u];							//�����ǰ���䱻�޸����串��
		long long t = 0;												//���ںϲ����������ѯ����ֵ
		if (lazy[u] != 0)pushdown(u, l, r);								//�����ǰ�ڵ���lazy��� �´����
		int mid = (l + r) >> 1;
		if (mid >= ll)t += ask(L(u), l, mid, ll, rr);					//���Ҫ��ѯ��������������н���
		if (mid < rr)t += ask(R(u), mid + 1, r, ll, rr);				//���Ҫ��ѯ���������Ҷ����н���
		return t;
	}
};

vector <int> nums;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	nums.resize(n + 1);
	for (int i = 1; i <= n; i++)cin >> nums[i];
	Segment_tree* segment = new Segment_tree(n, nums);
	for (int i = 0; i < m; i++) {
		int op, x, y, k;
		cin >> op;
		if (op == 1) {
			cin >> x >> y >> k;
			segment->change(1, 1, n, x, y, k);
		}
		else {
			cin >> x >> y;
			cout << segment->ask(1, 1, n, x, y) << "\n";
		}
	}
	return 0;
}