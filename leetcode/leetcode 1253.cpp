class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector <vector <int>> ans(2);
        ans[0].reserve(colsum.size());
        ans[1].reserve(colsum.size());
        for (int i : colsum){
            switch(i){
            case 0:
                ans[0].push_back(0);
                ans[1].push_back(0);
                break;
            case 1:
                if (upper >= lower){
                    upper--;
                    ans[0].push_back(1);
                    ans[1].push_back(0);
                }
                else{
                    lower--;
                    ans[0].push_back(0);
                    ans[1].push_back(1);
                }
                break;
            case 2:
                ans[0].push_back(1);
                ans[1].push_back(1);
                upper-- , lower--;
                break;
            }
        }
        if (upper != 0 || lower != 0) ans.clear();
        return ans;
    }
};