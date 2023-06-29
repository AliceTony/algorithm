class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size() , m = colSum.size();
        vector <vector <int>> ans(n , vector <int> (m , 0));
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                int temp = min(rowSum[i] , colSum[j]);
                ans[i][j] = temp;
                rowSum[i] -= temp;
                colSum[j] -= temp;
                if (!rowSum[i]) break;
            }
        }
        return ans;
    }
};