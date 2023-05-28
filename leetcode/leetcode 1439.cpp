//��������� ���������������Լ���˼·д
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<int> prev = mat[0];
        for (int i = 1; i < m; ++i) {
            prev = move(merge(prev, mat[i], k));
        }
        return prev[k - 1];
    }

    vector<int> merge(const vector<int>& f, const vector<int>& g, int k) {
        int left = f[0] + g[0], right = f.back() + g.back(), thres = 0;
        k = min(k, static_cast<int>(f.size() * g.size()));
        while (left <= right) {
            int mid = (left + right) / 2;
            int rptr = g.size() - 1, cnt = 0;
            for (int lptr = 0; lptr < f.size(); ++lptr) {
                while (rptr >= 0 && f[lptr] + g[rptr] > mid) {
                    --rptr;
                }
                cnt += rptr + 1;
            }
            if (cnt >= k) {
                thres = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        vector<int> ans;
        for (int i = 0; i < f.size(); ++i) {
            for (int j = 0; j < g.size(); ++j) {
                if (int sum = f[i] + g[j]; sum < thres) {
                    ans.push_back(sum);
                }
                else {
                    break;
                }
            }
        }
        while (ans.size() < k) {
            ans.push_back(thres);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

