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
    leetcode 1172 ����ջ
    https://leetcode.cn/problems/dinner-plate-stacks/
*/
typedef long long llint;
typedef pair<int, int> PII;

class DinnerPlates {
private:
    static const int N = 2e5 + 1;
    int capactity_max;                                                              //�������ֵ
    int now = 0;                                                                    //��ǰ����λ�õĶ�β
    int mark_push[N];                                                               //��ǵ�ǰ�Ƿ��ڲ������
    int mark_pop[N];                                                                //��ǵ�ǰ�Ƿ��ڵ�������
    priority_queue<int, vector<int>, less<int>> pq_pop;                             //ά����������
    priority_queue<int, vector<int>, greater<int>> pq_push;                         //ά���������
    vector <int> cap[N];                                                            //ģ��ջ

    void add_push(int index) {                                                      //�������ά������
        mark_push[index] = 1;
        pq_push.push(index);
    }

    void del_push(int index) {
        mark_push[index] = 0;
        pq_push.pop();
    }
    void add_pop(int index) {                                                       //��ǰλ��ӵ������ ���뵯������
        mark_pop[index] = 1;
        pq_pop.push(index);
    }

    void del_pop(int index) {
        mark_pop[index] = 0;
        pq_pop.pop();
    }

    int get_ans(int index) {                                                        //��ȡ��ǰջ��
        int ans = cap[index].back();                                                //��ȡ��ǰջ��ջ��
        cap[index].pop_back();                                                      //����ջ��
        return ans;
    }

public:

    DinnerPlates(int capacity) {                                                    //����ʼֵ
        capactity_max = capacity;
    }

    void push(int val) {                                                            //��val ���� �������ҵ�һ�� û������ջ��
        if (pq_push.empty()) {                                                      //����������Ϊ�� ˵������Ҫά��֮ǰ��ջ,�����µ�ջ���Ҽ���ά������
            cap[now].push_back(val);
            if (capactity_max > 1) add_push(now);                                   //��������������1 �´���Ҫά����ջ
            add_pop(now);
            now++;
        }
        else {                                                                      //֮ǰ��λ��ӵ����Ҫά����ջ
            int t = pq_push.top();                                                  //��ȡ��ǰ���е���Сֵ
            cap[t].push_back(val);
            if (cap[t].size() == capactity_max) del_push(t);                        //����Ѿ������������� ˵������Ҫ����ά���� ��������
            if (!mark_pop[t]) add_pop(t);                                           //��ǰλ��ӵ������ ���뵯������
        }
        return;
    }

    int pop() {                                                                     //�������������һ�� �ǿ�ջ������ֵ
        while (!pq_pop.empty()) {                                                   //����������в�Ϊ�� ˵��ӵ�п��ܴ��ڿ��Ե���������
            int t = pq_pop.top();                                                   //��ȡ��ǰ���е����ֵ
            if (cap[t].empty()) {                                                   //�����ǰջΪ�� ����ǰλ�õ������� ������һ��ѭ��
                del_pop(t);
                continue;
            }
            if (cap[t].size() - 1 == 0) {                                           //������ǰջ�� ջΪ�� ����ǰλ�õ�������
                del_pop(t);
            }
            if (!mark_push[t]) add_push(t);                                         //�������ά������
            return get_ans(t);
        }
        return -1;                                                                  //�����ڿɵ��������� ����-1
    }

    int popAtStack(int index) {                                                     //�����±��ջ��ջ��
        if (cap[index].empty()) return -1;                                          //��ǰ�±겻���ڿɵ�������
        if (!mark_push[index]) add_push(index);
        return get_ans(index);
    }
};