#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
    enum STATE
    {
        HOLD,
        COLD,
        SELL,
    };
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(3, 0);
        vector<int> temp(3, 0);
        dp[HOLD] = -prices[0];

        for (size_t i = 1; i < n; i++)
        {
            temp[HOLD] = max(dp[HOLD], dp[SELL] - prices[i]);
            temp[COLD] = dp[0] + prices[i];
            temp[SELL] = max(dp[COLD], dp[SELL]);
            dp = temp;
        }

        return max(dp[COLD], dp[SELL]);
    }
};