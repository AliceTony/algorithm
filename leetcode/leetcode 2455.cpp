class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        double sum = 0;
        for (int i : nums) {
            if (i % 6 == 0) {
                sum += i;
                cnt++;
            }
        }
        return sum / max(cnt, 1);
    }
};