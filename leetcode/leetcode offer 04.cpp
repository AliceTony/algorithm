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
    leetcode offer 04 二维数组中的查找
    https://leetcode.cn/problems/longest-arithmetic-subsequence/submissions/
*/

class Solution {
private:

public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) return 0;         //如果数组为空不可能找到 返回0
        int cols = matrix.size(), rows = matrix.front().size();         //确定数组范围
        for (int i = 0; i < cols; i++) {
            int l = 0, r = rows, mid;                                   //设定二分边界
            while (l + 1 < r) {                                         //二分查找
                mid = (l + r) >> 1;
                if (matrix[i][mid] <= target) l = mid;
                else r = mid;
            }
            if (matrix[i][l] == target) return 1;                       //如果当前值是对象值 返回1
        }
        return 0;                                                       //查找不到对象
    }
};