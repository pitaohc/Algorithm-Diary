#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class MinStack {

private:
    stack<int>data;
    stack<int> min_stack;
public:
    MinStack() {
        data = stack<int>();
        min_stack = stack<int>();

    }

    void push(int val) {
        data.push(val);
        int currentMin = getMin();
        if (currentMin >= val) { //判断当前元素是否小于等于最小栈的栈顶元素
            min_stack.push(val);
        }
    }

    void pop() {
        int val = top();
        int minVal = getMin();
        if (val == minVal) { //判断最小栈和数据栈的栈顶元素是否相同
            min_stack.pop();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min_stack.empty() ? INT_MAX : min_stack.top();
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
