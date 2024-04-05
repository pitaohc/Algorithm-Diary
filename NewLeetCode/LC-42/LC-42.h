#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        const int n = height.size();
        for (size_t i = 0; i < n; i++)
        {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top(); // 栈顶的高度
                stk.pop(); //出栈
                if (stk.empty()) {// case [1] <- 2
                    break;
                }
                int left = stk.top(); // 左边界
                int curWidth = i - left - 1;
                int curHeight = min(height[left], height[i]) - height[top];
#ifdef _DEBUG

            fmt::print("{}: res = {} + {} * {}\n", i, res, stk);
#endif // _DEBUG
                res += curWidth * curHeight;
            }
            stk.push(i);
#ifdef _DEBUG
            fmt::print("{}: ans = {}, stack = {}\n", i, res, stk);
#endif // _DEBUG

        }
        return res;
    }
};
