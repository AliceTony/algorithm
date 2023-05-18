#include <iostream>

#define L(u) u << 1													//��ǰ�ڵ������
#define R(u) u << 1 | 1												//��ǰ�ڵ���Һ���

using namespace std;

const int N = 1e5 + 7;

long long lazy[N << 2];												//lazy���
long long ans[N << 2];												//�����ֵ �� Ҷ�ӽڵ�ֵ														

int n, m;															//nΪ������� mΪ��������
int arr[N];															//�����ԭʼ����
int op, x, y, k;													//����ָʾ��

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