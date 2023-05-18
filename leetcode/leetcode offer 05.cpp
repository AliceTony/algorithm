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
    leetcode offer 05 替换空格
    https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
*/

class Solution {
public:
    string replaceSpace(string s) {
        string ans;                         //生成将要返回的字符串
        for (char i : s) {                  //遍历字符串s
            if (i == ' ')ans += "%20";      //如果是空格在尾部加入%20
            else ans += i;                  //否则插入当前值
        }
        return ans;
    }
};
