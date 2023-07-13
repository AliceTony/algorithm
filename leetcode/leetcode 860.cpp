class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num1 = 0, num2 = 0;
        for (int i : bills) {
            if (i == 5) num1++;
            else if (i == 10) {
                if (num1--) num2++;
                else return 0;
            }
            else {
                if (num1 && num2) num1--, num2--;
                else if (num1 >= 3) num1 -= 3;
                else return 0;
            }
        }
        return 1;
    }
};