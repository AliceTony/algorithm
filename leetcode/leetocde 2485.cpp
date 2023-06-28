class Solution {
private:
    int sum(int l , int r){
        return (l + r) * (r - l + 1) / 2;
    }
public:
    int pivotInteger(int n) {
        int l = 1 , r = n;
        while(l + 1< r){
            int mid = (l + r) >> 1;
            if(sum(1 , mid) <= sum(mid , n))l = mid;
            else r = mid;
        }
        if (sum(1 , l) == sum(l , n)) return l;
        else return -1;
    }
};