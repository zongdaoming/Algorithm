#include <iostream>
#include <string>
#include <cstdio>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;


class MyStack {
public:
    queue<int> qu_in;
    queue<int> qu_out;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // 保证qu_in对列中始终只有一个刚进来的元素
        qu_in.push(x);
        while(!qu_out.empty())
        {
            qu_in.push(qu_out.front());
            qu_out.pop();
        }
        swap(qu_in,qu_out);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = qu_out.front();
        qu_out.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return qu_out.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(qu_in.empty() && qu_out.empty())
        {
            return true;
        }
        return false;
    }
};


class MyStack {
public:
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }
    
    /** Get the top element. */
    int top() {
        int r = q.front();
        return r;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */



