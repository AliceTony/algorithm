template <typename val_t>
class priority_queue_less{
private:
#define L(u) u << 1
#define R(u) (u << 1 | 1)
    int len = 0;
    std::vector <val_t> pri;
    void down(int u){
        bool ok = false;
        if (R(u) < len && pri[R(u)] < pri[L(u)])ok = true;
        if (L(u) < len){
            if (!ok && pri[L(u)] < pri[u]){
                std::swap(pri[L(u)] , pri[u]);
                down(L(u));
            }
            else if (ok && pri[R(u)] < pri[u]){
                std::swap(pri[R(u)] , pri[u]);
                down(R(u));
            }
        }
    }

    void up(int u){
        if (u > 1 && pri[u] < pri[u >> 1]){
            std::swap(pri[u] , pri[u >> 1]);
            up(u >> 1);
        }
    }

    void dfs(int u){
        if (L(u) < len) dfs(L(u));
        if (R(u) < len) dfs (R(u));
        down(u);
    }

public:
    priority_queue_less(){
        pri.clear();
        pri.push_back(0);
    }

    void insert(val_t num){
        pri.push_back(num);
        len++;
        up(len);
    }

    void bulid(std::vector <val_t> arr){
        pri.clear();
        pri.push_back(0);
        pri.reserve(arr.size());
        for (int i : arr)pri.push_back(i);
        len = arr.size() + 1;
        dfs(1);
    }

    void pop(){
        std::swap(pri[1] , pri.back());
        pri.pop_back();
        len--;
        if (pri.size() > 1)down(1);
    }

    val_t top(){
        if (pri.size() > 1)return pri[1];
        else return 0;
    }
    
    ~priority_queue_less(){
        pri.clear();
    }
};