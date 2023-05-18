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
                if (temperatures[i] > temperatures[v.back()]) {      //�����ǰ�¶�ֵ���ڶ�β�¶�ֵ �����ҵ����ߵ��¶� 
                    ans[v.back()] = i - v.back();                   //����Ϊ��Ӧ����������
                    v.pop_back();                                   //������βԪ��
                }
                else break;
            }
            v.push_back(i);                                         //����ǰԪ�ؼ��뵽��β
        }
        return ans;
    }
};