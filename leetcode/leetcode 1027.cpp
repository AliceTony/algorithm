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
    leetcode 1027 ��Ȳ�����
    https://leetcode.cn/problems/longest-arithmetic-subsequence/submissions/
*/

class Solution {
private:
    static const int N = 1e3 + 7, MID = 500;
    int f[N][N];                                        //��ʼ��DP����
public:
    int longestArithSeqLength(vector<int>& nums) {
        int len = nums.size();                          //��ȡ���鳤��
        int ans = 0;                                    //��ʼ������ֵ
        for (int i = 1; i < len; i++) {                 //���±�1��ʼ��������
            for (int k = 0; k < i; k++) {               //����֮ǰ����
                int j = nums[i] - nums[k] + MID;        //��ȡ��ֵ
                f[i][j] = max(f[i][j], f[k][j] + 1);    //״̬ת�Ʒ��� ��֮ǰ��k��̳еȲ�����
                ans = max(f[i][j], ans);                //��¼���
            }
        }
        return ++ans;                                   //���ؽ�� (����ͳ�Ƶ�0��)
    }
};

