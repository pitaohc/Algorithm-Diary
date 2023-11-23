#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class MyQueue {
private:
    stack<int> first;
    stack<int> second;
public:
    MyQueue() {
        first = stack<int>();
        second = stack<int>();
    }

    void push(int x) {
        first.push(x);
    }

    int pop() {
        int temp = peek();
        second.pop();
        return temp;
    }

    int peek() {
        if (second.empty()) {
            while (!first.empty()) {
                second.push(first.top());
                first.pop();
            }
        }
        return second.top();
    }

    bool empty() {
        return first.empty() && second.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
