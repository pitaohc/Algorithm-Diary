#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    vector<vector<int>> dp; //记忆化搜索
public:
    const vector<int>& process(int n)
    {
        if (!dp[n].empty()) //如果已经有答案，则直接返回
        {
            return dp[n];
        }
        const vector<int>& left = process(n / 2 + (n % 2));
        const vector<int>& right = process(n / 2);

        dp[n].resize(left.size() + right.size());

        for (int i = 0; i < left.size(); ++i)
        {
            dp[n][i] = 2 * left[i] - 1; //单数组成左半边
        }
        for (int i = 0; i < right.size(); ++i)
        {
            dp[n][i + left.size()] = 2 * right[i]; //双数组成右半边
        }
        return dp[n];
    }
    vector<int> beautifulArray(int n) {
        dp = vector<vector<int>>(max(n + 1, 3)); //max不用特判1和2
        dp[1] = { 1 };
        dp[2] = { 1,2 };
        process(n);

        return dp[n];
    }
};