class MinStack {
private:
    vector <int> ans;
    vector <int> ans_min;
public:
    MinStack() {

    }
    
    void push(int val) {
        ans.push_back(val);
        if (ans_min.empty() || val <= ans_min.back()) ans_min.push_back(val);
    }
    
    void pop() {
        if (ans_min.back() == ans.back())ans_min.pop_back();
        ans.pop_back();
    }
    
    int top() {
        return ans.back();
    }
    
    int getMin() {
        return ans_min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */