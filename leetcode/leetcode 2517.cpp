class Solution {
private:
    int n;
    bool check(vector<int>& price, int k, int target) {
        int cnt = 1;
        int last = price.front();
        for (int i = 1; i < n; i++) {
            if (price[i] - last >= target) {
                cnt++;
                last = price[i];
            }
        }
        return cnt >= k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price.back() - price.front() + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(price, k, mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};