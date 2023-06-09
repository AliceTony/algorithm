class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (n && !flowerbed[0]) n--;
            return !n;
        }
        for (int i = 0; n && i < flowerbed.size(); i++) {
            if (i == 0) {
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)n--, flowerbed[i] = 1;
            }
            else if (i == flowerbed.size() - 1) {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)n--, flowerbed[i] = 1;
            }
            else {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) n--, flowerbed[i] = 1;
            }
        }
        return !n;
    }
};