class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector <int>> um;
        for (int i = 0; i < words.size(); i++) {
            string mark;
            for (int j = 1; j < words[i].size(); j++) {
                mark += char(words[i][j] - words[i][j - 1] + 30);
            }
            um[mark].push_back(i);
        }
        for (auto i : um) {
            if (i.second.size() == 1) return words[i.second.front()];
        }
        return 0;
    }
};