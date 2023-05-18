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
    leetcode offer 04 ��ά�����еĲ���
    https://leetcode.cn/problems/longest-arithmetic-subsequence/submissions/
*/

class Solution {
private:

public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) return 0;         //�������Ϊ�ղ������ҵ� ����0
        int cols = matrix.size(), rows = matrix.front().size();         //ȷ�����鷶Χ
        for (int i = 0; i < cols; i++) {
            int l = 0, r = rows, mid;                                   //�趨���ֱ߽�
            while (l + 1 < r) {                                         //���ֲ���
                mid = (l + r) >> 1;
                if (matrix[i][mid] <= target) l = mid;
                else r = mid;
            }
            if (matrix[i][l] == target) return 1;                       //�����ǰֵ�Ƕ���ֵ ����1
        }
        return 0;                                                       //���Ҳ�������
    }
};