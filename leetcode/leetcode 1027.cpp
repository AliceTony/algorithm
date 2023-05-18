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
    leetcode 1027 最长等差数列
    https://leetcode.cn/problems/longest-arithmetic-subsequence/submissions/
*/

class Solution {
private:
    static const int N = 1e3 + 7, MID = 500;
    int f[N][N];                                        //初始化DP数组
public:
    int longestArithSeqLength(vector<int>& nums) {
        int len = nums.size();                          //获取数组长度
        int ans = 0;                                    //初始化返回值
        for (int i = 1; i < len; i++) {                 //从下标1开始遍历数组
            for (int k = 0; k < i; k++) {               //遍历之前的数
                int j = nums[i] - nums[k] + MID;        //获取差值
                f[i][j] = max(f[i][j], f[k][j] + 1);    //状态转移方程 从之前第k项继承等差数列
                ans = max(f[i][j], ans);                //记录结果
            }
        }
        return ++ans;                                   //返回结果 (额外统计第0项)
    }
};

