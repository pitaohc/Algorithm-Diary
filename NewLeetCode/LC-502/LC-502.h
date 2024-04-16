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
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //注意，优先队列的比较函数是相反的
        auto cmp = [&](int left, int right) {
            return (capital[left] != capital[right]) ?
                capital[left] > capital[right] : profits[left] < profits[right];
            };
        auto cmp2 = [&](int left, int right) {
            return profits[left] < profits[right]; // 谁小谁排后面
            };
        priority_queue<int, vector<int>, decltype(cmp) > gpq(cmp); // 存放未达到最小资本的项目序号
        priority_queue<int, vector<int>, decltype(cmp2) > lpq(cmp2); // 存放已经达到最小资本的项目序号
        const int n = profits.size();
        for (int i = 0; i < n; i++)
        {
            gpq.push(i);
        }
#ifdef _DEBUG
        fmt::print("所有项目:{}\n", gpq);
#endif // _DEBUG

        for (int i = 0; i < k; i++)
        {
            while (!gpq.empty() && w >= capital[gpq.top()]) { // 有可以新增的投资项目
                lpq.push(gpq.top());
                gpq.pop();
            }
            if (lpq.empty()) { // 无可用投资项目
                break;
            }
            w += profits[lpq.top()];
            lpq.pop();
            //#ifdef _DEBUG
            //            fmt::print("{}: 可投资项目：{}, 不满足项目：{}, w = {}\n", gpq, lpq, w);
            //#endif // _DEBUG

        }


        return w;
    }
};

