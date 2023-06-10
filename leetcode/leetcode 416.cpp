class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum & 1) return 0;
        int target = sum / 2;
        unordered_set <int> vis;
        vector <int> mark;
        vis.insert(0);
        for (int i : nums){
            mark.clear();
            for (int j : vis){
                if (i + j <= target && !vis.count(i + j)) {
                    mark.push_back(i + j);
                }
            }
            for (int j : mark) vis.insert(j);
        }
        return vis.count(target);
    }
};