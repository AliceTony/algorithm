class Fancy {
private:
    #define L(u) u << 1
    #define R(u) u << 1 | 1
    typedef long long llint;
    static const int N = 1e5 , MOD = 1e9 + 7;
    int len = 0;
    llint tree[N << 2] , lazy_add[N << 2] , lazy_mul[N << 2];
    void pushdown(int u , int l , int r){
        int mid = (l + r) >> 1;
        tree[L(u)] = lazy_mul[u] * tree[L(u)] + lazy_add[u] * llint(mid - l + 1);
        tree[R(u)] = lazy_mul[u] * tree[R(u)] + lazy_add[u] * llint(r - mid);
        lazy_mul[L(u)] *= lazy_mul[u];
        lazy_add[L(u)] = lazy_add[L(u)] * lazy_mul[u] + lazy_add[u];
        lazy_mul[R(u)] *= lazy_mul[u];
        lazy_add[R(u)] = lazy_add[R(u)] * lazy_mul[u] + lazy_add[u];
        if (tree[L(u)] >= MOD)tree[L(u)] %= MOD;															
	    if (lazy_mul[L(u)] >= MOD) lazy_mul[L(u)] %= MOD;
	    if (lazy_add[L(u)] >= MOD) lazy_add[L(u)] %= MOD;
	    if (tree[R(u)] >= MOD)tree[R(u)] %= MOD;
	    if (lazy_mul[R(u)] >= MOD) lazy_mul[R(u)] %= MOD;
	    if (lazy_add[R(u)] >= MOD) lazy_add[R(u)] %= MOD;
	    lazy_add[u] = 0, lazy_mul[u] = 1;
    }
    int ask(int u , int l , int r , int ll , int rr){
        if (l >= ll && r <= rr) return tree[u];
        llint t = 0;
        if (lazy_add[u] || lazy_mul[u] != 1)pushdown(u , l , r);
        int mid = (l + r) >> 1;
        if (mid >= ll) t += ask(L(u) , l , mid , ll , rr);
        if (mid < rr) t += ask(R(u) , mid + 1 , r , ll , rr);
        return t % MOD;
    }
    void change(int u , int l , int r ,int ll , int rr , llint k , bool ok){
        if (l >= ll  && r <= rr){
            if (ok){
                tree[u] *= k;
                lazy_add[u] *= k;
                lazy_mul[u] *= k;
            }
            else {
                tree[u] += k * llint(r - l + 1);
                lazy_add[u] += k;
            }
            if (tree[u] >= MOD) tree[u] %= MOD;
            if (lazy_add[u] >= MOD) lazy_add[u] %= MOD;
            if (lazy_mul[u] >= MOD) lazy_mul[u] %= MOD;
            return;
        }
        
        if (lazy_add[u] || lazy_mul[u] != 1) pushdown(u , l , r);
        int mid = (l + r) >> 1;
        if (mid >= ll) change(L(u) , l , mid , ll , rr , k , ok);
        if (mid < rr) change(R(u) , mid + 1 , r , ll , rr , k , ok);
        tree[u] = tree[L(u)] + tree[R(u)];
        if (tree[u] >= MOD) tree[u] %= MOD;
    }
public:
    Fancy() {
        memset(tree , 0 ,sizeof (tree));
        memset(lazy_add , 0 , sizeof (lazy_add));
        for (int i = 0;i < N << 2;i++) lazy_mul[i] = 1;
    }
    
    void append(int val) {
        len++;
        change(1 , 1 , N , len , len , val , 0);
    }
    
    
    void addAll(int inc) {
        if (len) change(1 , 1 , N , 1 , len , inc , 0);
    }
    
    void multAll(int m) {
        change(1 , 1 , N , 1 , len , m , 1);
    }
    
    int getIndex(int idx) {
        if (idx >= len) return -1;
        return ask(1 , 1 , N , idx + 1 , idx + 1);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */