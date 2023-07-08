class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.size() == 1) return stones.front();
        set <int> arr;
        int sum = accumulate(stones.begin() , stones.end() , 0) , target = sum / 2;
        arr.insert(0);
        vector <int> temp;
        for (int i : stones){
            temp.clear();
            for (int j : arr){
                if (i + j <= target) temp.push_back(i + j);
            }
            for (int j : temp) arr.insert(j);
        }
        return (target - *arr.rbegin()) * 2 + (sum & 1);
    }
};