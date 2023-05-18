class Solution {
private:
    typedef pair<int, int> PII;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> ans(n, 0);
        vector <int> v;
        for (int i = 0; i < n; i++) {
            while (!v.empty()) {
                if (temperatures[i] > temperatures[v.back()]) {      //如果当前温度值大于队尾温度值 代表找到升高的温度 
                    ans[v.back()] = i - v.back();                   //天数为对应天数到今天
                    v.pop_back();                                   //弹出队尾元素
                }
                else break;
            }
            v.push_back(i);                                         //将当前元素加入到队尾
        }
        return ans;
    }
};