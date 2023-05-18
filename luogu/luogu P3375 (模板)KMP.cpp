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
    luogu P3375 (模板)KMP
    https://www.luogu.com.cn/problem/P3375
*/

typedef long long llint;
typedef pair<int, int> PII;

static const int N = 1e6 + 7;

char s1[N], s2[N];

class KMP {
private:
    char* str;                                                              //存放模式串
    int n;                                                                  //存放模式串长度
    vector<int> next;                                                       //存放匹配失败后回退位置
public:
    KMP(char s1[]) {
        count_next(s1);
    }
    void count_next(char s[]) {                                             //计算next数组
        str = s;
        n = strlen(s);
        next.resize(n);
        next[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {                                //从下标为1开始计算next数组
            while (j && str[i] != str[j]) j = next[j - 1];                  //当j不为0时 且匹配失败 进行回退
            if (str[j] == str[i])j++;                                       //如果成功匹配j++
            next[i] = j;
        }
    }
    vector <int> check(char s[]) {                                          //进行字符串匹配
        vector <int> res;
        int len = strlen(s);
        for (int i = 0, j = 0; i < len; i++) {                              //进行字符匹配
            while (j && s[i] != str[j]) j = next[j - 1];                    //当j不为0且匹配失败 进行回退
            if (s[i] == str[j]) j++;                                        //匹配成功j++
            if (j == n) res.push_back(i - n + 2), j = next[j - 1];          //完整匹配成功字符串 存放字符串出现位置
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