class Solution {
private:
    typedef pair<int, int> PII;
public:
    int sum(int bucket, int vat) {
        return ceil(vat / (bucket * 1.0));
    }
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int cnt = 0, ans = INT_MAX;
        int n = bucket.size();
        priority_queue<PII, vector <PII>, less<PII>> pq;
        for (int i = 0; i < n; i++) {
            if (vat[i] && !bucket[i]) bucket[i]++, cnt++;
            if (bucket[i] && vat[i]) pq.push({ sum(bucket[i] , vat[i]) , i });
        }
        if (pq.empty()) return 0;
        while (1) {
            auto [val, i] = pq.top();
            pq.pop();
            ans = min(ans, cnt + val);
            if (val == 1) break;
            int t = (vat[i] + val - 2) / (val - 1);
            cnt += t - bucket[i];
            bucket[i] = t;
            pq.push({ sum(bucket[i] , vat[i]) , i });
        }
        return ans;
    }
};