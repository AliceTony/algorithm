#include <iostream>

#define L(u) u << 1																				//��ǰ�ڵ������
#define R(u) u << 1 | 1																			//��ǰ�ڵ���Һ���

using namespace std;

const int N = 1e5 + 7;

long long lazy_add[N << 2];																		//lazy���
long long lazy_mul[N << 2];																		//lazy���
long long ans[N << 2];																			//�����ֵ �� Ҷ�ӽڵ�ֵ														

int n, m, p;																					//nΪ������� mΪ�������� pΪģ��
int arr[N];																						//�����ԭʼ����
int op, x, y, k;																				//����ָʾ��

void bulid(int u, int l, int r) {																//�����߶���
	lazy_mul[u]++;																				//��ʼ��mul���
	if (l == r) {																				//������Ҷ�ӽڵ� ����ݹ��Ե
		ans[u] = arr[r];																		//��ֵ��Ҷ�ӽڵ�
		return;
	}
	int mid = (l + r) >> 1;
	bulid(L(u), l, mid);																		//���������
	bulid(R(u), mid + 1, r);																	//�����Ҷ���
	ans[u] = ans[L(u)] + ans[R(u)];																//��ֵ���׽ڵ�������
}


void pushdown(int u, int l, int r) {															//�·�lazy���
	int mid = (l + r) >> 1;
	ans[L(u)] = lazy_mul[u] * ans[L(u)] + lazy_add[u] * (long long)(mid - l + 1);				//��������ansֵ
	ans[R(u)] = lazy_mul[u] * ans[R(u)] + lazy_add[u] * (long long)(r - mid);					//�����Һ���ansֵ
	lazy_mul[L(u)] *= lazy_mul[u];																//��������mul���
	lazy_add[L(u)] = lazy_add[L(u)] * lazy_mul[u] + lazy_add[u];								//��������add���
	lazy_mul[R(u)] *= lazy_mul[u];																//�����Һ���mul���
	lazy_add[R(u)] = lazy_add[R(u)] * lazy_mul[u] + lazy_add[u];								//�����Һ���add���
	if (ans[L(u)] >= p)ans[L(u)] %= p;															//��������%p
	if (lazy_mul[L(u)] >= p) lazy_mul[L(u)] %= p;
	if (lazy_add[L(u)] >= p) lazy_add[L(u)] %= p;
	if (ans[R(u)] >= p)ans[R(u)] %= p;
	if (lazy_mul[R(u)] >= p) lazy_mul[R(u)] %= p;
	if (lazy_add[R(u)] >= p) lazy_add[R(u)] %= p;
	lazy_add[u] = 0, lazy_mul[u] = 1;															//������׵�lazy���
}


void change(int u, int l, int r, int ll, int rr, long long k, int ok) {							//�����޸��߶���
	if (l >= ll && r <= rr) {																	//�����ǰ���䱻�޸����串��
		if (ok) {																				//�����ǰִ�е�������ӷ�
			ans[u] += k * (long long)(r - l + 1);												//��ǰ�ڵ������+k*��������������
			lazy_add[u] += k;																	//����add���
		}
		else {																					//�����ǰִ�е�������˷�
			ans[u] *= k;																		//��ǰ�ڵ�������*=k
			lazy_add[u] *= k;																	//���µ�ǰ�ڵ��add���
			lazy_mul[u] *= k;																	//���µ�ǰ�ڵ��mul���
		}
		if (ans[u] >= p) ans[u] %= p;															//��������%p
		if (lazy_add[u] >= p)lazy_add[u] %= p;
		if (lazy_mul[u] >= p)lazy_mul[u] %= p;
		return;
	}
	if (lazy_add[u] || lazy_mul[u] != 1)pushdown(u, l, r);									//�����ǰ�ڵ���lazy��� �´����
	int mid = (l + r) >> 1;
	if (mid >= ll) change(L(u), l, mid, ll, rr, k, ok);											//���Ҫ�޸ĵ�������������н���
	if (mid < rr) change(R(u), mid + 1, r, ll, rr, k, ok);										//���Ҫ�޸ĵ��������Ҷ����н���
	ans[u] = ans[L(u)] + ans[R(u)];																//���¸��׽ڵ�������
	if (ans[u] >= p) ans[u] %= p;
}


long long ask(int u, int l, int r, int ll, int rr) {											//�����ѯ
	if (l >= ll && r <= rr)return ans[u];														//�����ǰ���䱻�޸����串��
	long long t = 0;																			//���ںϲ����������ѯ����ֵ
	if (lazy_add[u] || lazy_mul[u] != 1)pushdown(u, l, r);									//�����ǰ�ڵ���lazy��� �´����
	int mid = (l + r) >> 1;
	if (mid >= ll)t += ask(L(u), l, mid, ll, rr);												//���Ҫ��ѯ��������������н���
	if (mid < rr)t += ask(R(u), mid + 1, r, ll, rr);											//���Ҫ��ѯ���������Ҷ����н���
	return t % p;
}
