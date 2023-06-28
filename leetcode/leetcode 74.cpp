class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0 , r = matrix.size();
        while(l + 1 < r){
            int mid = (l + r) >> 1;
            if (matrix[mid].front() <= target) l = mid;
            else r = mid;
        }
        int num = l;
        l = 0 , r = matrix[num].size();
        while(l + 1 < r){
            int mid = (l + r) >> 1;
            if (matrix[num][mid] <= target) l = mid;
            else r = mid;
        }
        return matrix[num][l] == target;
    }
};