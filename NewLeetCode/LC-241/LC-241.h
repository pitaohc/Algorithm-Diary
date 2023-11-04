#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
    vector<int> nums;
    vector<char> ops;
    vector<vector<vector<int>>> dp; //记忆化搜索，存储中间状态
public:
    void getStatus(int begin, int diff, int end)
    {
        vector<int> status;
        for (auto left : dp[begin][diff])
        {
            for (auto right : dp[diff + 1][end])
            {
                int val = 0;
                switch (ops[diff])
                {
                case '+': val = left + right; break;
                case '-': val = left - right; break;
                case '*': val = left * right; break;
                }
                dp[begin][end].push_back(val);
            }
        }

    }
    vector<int> diffWaysToCompute(string expression) {
        nums.clear();
        ops.clear();
        int num = 0;
        char op = ' ';
        istringstream ss(expression + "+");
        while (ss >> num && ss >> op) //获取所有的数字和运算符
        {
            nums.push_back(num);
            ops.push_back(op);
        }
        int n = nums.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>()));
        for (int i = 0; i < n; ++i) //遍历结束位置
        {
            for (int j = i; j >= 0; --j) //遍历开始位置
            {
                if (i != j) //如果不止一个数字
                {
                    for (int k = j; k < i; ++k) //遍历分割位置
                    {
                        getStatus(j, k, i);
                    }
                }
                else//如果只有一个数字
                {
                    dp[j][i].push_back(nums[i]);
                }
            }
        }
        return dp[0][n - 1]; //返回从0开始，到n-1结束的状态
    }
};