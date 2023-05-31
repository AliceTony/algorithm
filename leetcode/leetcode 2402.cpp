class Solution {
private:
    vector <int> vis;
    typedef pair <int, int> PII;
    typedef pair <long, int> PLI;
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vis.resize(n);
        vector <PII> time;
        for (auto i : meetings) time.push_back({ i[0] , i[1] - i[0] });
        sort(time.begin(), time.end());
        priority_queue<int, vector<int>, greater<int>> number;
        for (int i = 0; i < n; i++)number.push(i);
        priority_queue<PLI, vector<PLI>, greater<PLI>> work_time;
        long long  now = 0;
        for (auto [s, work] : time) {
            now = now > s ? now : s;
            while (!work_time.empty() && work_time.top().first <= now) {
                number.push(work_time.top().second);
                work_time.pop();
            }
            if (number.empty()) {
                auto [x, t] = work_time.top();
                work_time.pop();
                now = x;
                work_time.push({ now + work , t });
                vis[t]++;
            }
            else {
                int t = number.top();
                number.pop();
                work_time.push({ now + work , t });
                vis[t]++;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (vis[ans] < vis[i]) ans = i;
        }
        return ans;
    }
};