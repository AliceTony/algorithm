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
    luogu P3375 (ģ��)KMP
    https://www.luogu.com.cn/problem/P3375
*/

typedef long long llint;
typedef pair<int, int> PII;

static const int N = 1e6 + 7;

char s1[N], s2[N];

class KMP {
private:
    char* str;                                                              //���ģʽ��
    int n;                                                                  //���ģʽ������
    vector<int> next;                                                       //���ƥ��ʧ�ܺ����λ��
public:
    KMP(char s1[]) {
        count_next(s1);
    }
    void count_next(char s[]) {                                             //����next����
        str = s;
        n = strlen(s);
        next.resize(n);
        next[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {                                //���±�Ϊ1��ʼ����next����
            while (j && str[i] != str[j]) j = next[j - 1];                  //��j��Ϊ0ʱ ��ƥ��ʧ�� ���л���
            if (str[j] == str[i])j++;                                       //����ɹ�ƥ��j++
            next[i] = j;
        }
    }
    vector <int> check(char s[]) {                                          //�����ַ���ƥ��
        vector <int> res;
        int len = strlen(s);
        for (int i = 0, j = 0; i < len; i++) {                              //�����ַ�ƥ��
            while (j && s[i] != str[j]) j = next[j - 1];                    //��j��Ϊ0��ƥ��ʧ�� ���л���
            if (s[i] == str[j]) j++;                                        //ƥ��ɹ�j++
            if (j == n) res.push_back(i - n + 2), j = next[j - 1];          //����ƥ��ɹ��ַ��� ����ַ�������λ��
        }
        return res;
    }
    vector <int> get_next() {
        return next;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> s1 >> s2;
    KMP* kmp = new KMP(s2);
    vector <int> ans, next;
    ans = kmp->check(s1);
    next = kmp->get_next();
    for (int i : ans) cout << i << "\n";
    for (int i : next) cout << i << " ";
    return 0;
}