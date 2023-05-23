class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        multimap<int, int> arr;
        int n = values.size();
        for (int i = 0; i < n; i++) arr.insert({ values[i] , labels[i] });
        unordered_map <int, int> mark;
        int ans = 0;
        for (auto i = arr.rbegin(); i != arr.rend(); i++) {
            if (mark[i->second] < useLimit) {
                mark[i->second]++;
                ans += i->first;
                if (--numWanted == 0) break;
            }
        }
        return ans;
    }
};