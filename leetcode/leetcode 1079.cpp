class Solution {
private:
    int n;
    vector <bool> vis;
    string str;
    unordered_set <string> ans;
public:
    void all_check(string& tiles) {
        ans.insert(str);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                str += tiles[i];
                vis[i] = 1;
                all_check(tiles);
                str.pop_back();
                vis[i] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vis.resize(n);
        for (int i = 0; i < n; i++) {
            str += tiles[i];
            vis[i] = 1;
            all_check(tiles);
            str.pop_back();
            vis[i] = 0;
        }
        return ans.size();
    }
};