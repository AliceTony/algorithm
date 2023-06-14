class Solution {
public:
    double average(vector<int>& salary) {
        int minx = 1e9 , maxn = 0;
        double sum = 0;
        for (int i : salary){
            sum += i;
            minx = min (i , minx);
            maxn = max (i , maxn);
        }
        sum -= minx + maxn;
        return sum / (salary.size() - 2);
    }
};