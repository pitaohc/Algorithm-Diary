#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k > n)
        {
            int sum = 0;
            for (size_t i = 1; i < n; i++)
            {
                sum += (prices[i] - prices[i - 1] > 0) ? prices[i] : prices[i - 1] > 0;
            }
        }
        vector<int> buy(k + 1, -prices[0]), sell(k + 1, 0);
        //buy[i]代表第i次买入后的最大利润
        //sell[i]代表第i次卖出后的最大利润
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                //目前的最大买入后利润，前一次的卖出利润-当前价格
                sell[j] = max(sell[j], buy[j] + prices[i]);
                //目前的最大卖出后利润，当前次买入利润+当前价格
            }
        }
        return sell[k];
    }
};