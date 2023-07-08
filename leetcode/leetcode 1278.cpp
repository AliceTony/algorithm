class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector <long long> ans;
        if (finalSum & 1) return ans;
        long long sum = 0;
        for (int i = 2; ;i += 2){
            if (sum + i < finalSum - i){
                ans.push_back(i);
                sum += i;
            } 
            else {
                ans.push_back(finalSum - sum);
                break;
            }
        }
        return ans;
    }
};