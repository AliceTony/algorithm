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
    leetcode offer 05 �滻�ո�
    https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
*/

class Solution {
public:
    string replaceSpace(string s) {
        string ans;                         //���ɽ�Ҫ���ص��ַ���
        for (char i : s) {                  //�����ַ���s
            if (i == ' ')ans += "%20";      //����ǿո���β������%20
            else ans += i;                  //������뵱ǰֵ
        }
        return ans;
    }
};
