class Solution {
private:
    typedef pair<int , int> PII;
    struct Node{
        int left_right;
        int pick;
        int right_left;
        int put;
        int number;
        Node (int left_right , int pick , int right_left , int put , int number) : left_right(left_right) , pick(pick) , right_left(right_left) , put(put) , number(number){}
        bool operator < (const Node &b) const {
            if (left_right + right_left != b.left_right + b.right_left) return left_right + right_left < b.left_right + b.right_left;
            else return number < b.number;
        } 
    };
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        vector <Node> arr;
        for (auto i : time) arr.push_back({i[0] , i[1] , i[2] , i[3] , int(arr.size())});
        priority_queue<Node> pq_toleft , pq_toright;
        priority_queue<PII , vector <PII> , greater<PII>> pq_pick , pq_put;
        for (auto i : arr) pq_toright.push(i);
        int ans = 0 , m = n;
        while(n){
            if (!pq_pick.empty() && pq_pick.top().first <= ans){
                while(!pq_pick.empty() && pq_pick.top().first <= ans){
                    pq_toleft.push({arr[pq_pick.top().second]});
                    pq_pick.pop();
                }
            }
            else if (!pq_put.empty() && pq_put.top().first <= ans){
                while(!pq_put.empty() && pq_put.top().first <= ans){
                    pq_toright.push({arr[pq_put.top().second]});
                    pq_put.pop();
                }
            }
            else if (!pq_toleft.empty()){
                Node t = pq_toleft.top();
                pq_toleft.pop();
                pq_put.push({ans + t.right_left + t.put , t.number});
                ans += t.right_left;
                n--;
            }
            else if (m && !pq_toright.empty()){
                Node t = pq_toright.top();
                pq_toright.pop();
                pq_pick.push({ans + t.left_right + t.pick , t.number});
                ans += t.left_right;
                m--;
            }
            
            else{
                if(pq_pick.empty()) ans = pq_put.top().first;
                else if (pq_put.empty()) ans = pq_pick.top().first;
                else {
                    if (pq_pick.top().first <= pq_put.top().first) ans = pq_pick.top().first;
                    else ans = pq_put.top().first;
                }
            }
        }
        return ans;
    }
};