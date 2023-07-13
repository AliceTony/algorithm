class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            int sum = people[r--];
            if (sum + people[l] <= limit)l++;
            ans++;
        }
        return ans;
    }
};