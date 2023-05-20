class NumArray {
private:
#define L(u) u << 1
#define R(u) u << 1 | 1
    int n;
    vector <int> tree;
    vector <int> arr;
    void bulid(int u, int l, int r) {
        if (l == r) {
            tree[u] = arr[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        if (mid >= l) bulid(L(u), l, mid);
        if (mid < r) bulid(R(u), mid + 1, r);
        tree[u] = tree[L(u)] + tree[R(u)];
    }

public:

    void change(int u, int l, int r, int ll, int rr, int k) {
        if (l == r) {
            tree[u] = k;
            return;
        }
        int mid = (l + r) >> 1;
        if (mid >= ll) change(L(u), l, mid, ll, rr, k);
        if (mid < rr) change(R(u), mid + 1, r, ll, rr, k);
        tree[u] = tree[L(u)] + tree[R(u)];
    }

    int ask(int u, int l, int r, int ll, int rr) {
        if (l >= ll && r <= rr) return tree[u];
        int mid = (l + r) >> 1;
        int t = 0;
        if (mid >= ll) t += ask(L(u), l, mid, ll, rr);
        if (mid < rr) t += ask(R(u), mid + 1, r, ll, rr);
        return t;
    }

    NumArray(vector<int>& nums) {
        arr = move(nums);
        n = arr.size();
        tree.resize((n << 2) + 1);
        bulid(1, 1, n);

    }


    void update(int index, int val) {
        change(1, 1, n, index + 1, index + 1, val);
    }

    int sumRange(int left, int right) {
        return ask(1, 1, n, left + 1, right + 1);
    }
};
