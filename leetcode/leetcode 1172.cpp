#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define L(u) u << 1
#define R(u) u << 1 | 1

using namespace std;

/*
    leetcode 1172 餐盘栈
    https://leetcode.cn/problems/dinner-plate-stacks/
*/
typedef long long llint;
typedef pair<int, int> PII;

class DinnerPlates {
private:
    static const int N = 2e5 + 1;
    int capactity_max;                                                              //容器最大值
    int now = 0;                                                                    //当前插入位置的队尾
    int mark_push[N];                                                               //标记当前是否在插入队列
    int mark_pop[N];                                                                //标记当前是否在弹出队列
    priority_queue<int, vector<int>, less<int>> pq_pop;                             //维护弹出队列
    priority_queue<int, vector<int>, greater<int>> pq_push;                         //维护插入队列
    vector <int> cap[N];                                                            //模拟栈

    void add_push(int index) {                                                      //加入插入维护队列
        mark_push[index] = 1;
        pq_push.push(index);
    }

    void del_push(int index) {
        mark_push[index] = 0;
        pq_push.pop();
    }
    void add_pop(int index) {                                                       //当前位置拥有数据 加入弹出队列
        mark_pop[index] = 1;
        pq_pop.push(index);
    }

    void del_pop(int index) {
        mark_pop[index] = 0;
        pq_pop.pop();
    }

    int get_ans(int index) {                                                        //获取当前栈顶
        int ans = cap[index].back();                                                //获取当前栈的栈顶
        cap[index].pop_back();                                                      //弹出栈顶
        return ans;
    }

public:

    DinnerPlates(int capacity) {                                                    //赋初始值
        capactity_max = capacity;
    }

    void push(int val) {                                                            //将val 推入 从左往右第一个 没有满的栈。
        if (pq_push.empty()) {                                                      //如果插入队列为空 说明不需要维护之前的栈,开将新的栈并且加入维护队列
            cap[now].push_back(val);
            if (capactity_max > 1) add_push(now);                                   //如果最大容量大于1 下次需要维护该栈
            add_pop(now);
            now++;
        }
        else {                                                                      //之前的位置拥有需要维护的栈
            int t = pq_push.top();                                                  //获取当前队列的最小值
            cap[t].push_back(val);
            if (cap[t].size() == capactity_max) del_push(t);                        //如果已经到达容器上限 说明不需要继续维护了 弹出队列
            if (!mark_pop[t]) add_pop(t);                                           //当前位置拥有数据 加入弹出队列
        }
        return;
    }

    int pop() {                                                                     //弹出从右往左第一个 非空栈顶部的值
        while (!pq_pop.empty()) {                                                   //如果弹出队列不为空 说明拥有可能存在可以弹出的数据
            int t = pq_pop.top();                                                   //获取当前队列的最大值
            if (cap[t].empty()) {                                                   //如果当前栈为空 将当前位置弹出队列 进行下一轮循环
                del_pop(t);
                continue;
            }
            if (cap[t].size() - 1 == 0) {                                           //弹出当前栈后 栈为空 将当前位置弹出队列
                del_pop(t);
            }
            if (!mark_push[t]) add_push(t);                                         //加入插入维护队列
            return get_ans(t);
        }
        return -1;                                                                  //不存在可弹出的数据 返回-1
    }

    int popAtStack(int index) {                                                     //弹出下标的栈的栈顶
        if (cap[index].empty()) return -1;                                          //当前下标不存在可弹出数据
        if (!mark_push[index]) add_push(index);
        return get_ans(index);
    }
};