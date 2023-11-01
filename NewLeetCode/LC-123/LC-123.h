#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy(3, -prices[0]), sell(3, 0);
        //buy[i]代表第i次买入后的最大利润
        //sell[i]代表第i次卖出后的最大利润
        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = 1; j < buy.size(); j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                //目前的最大买入后利润，前一次的卖出利润-当前价格
                sell[j] = max(sell[j], buy[j] + prices[i]);
                //目前的最大卖出后利润，当前次买入利润+当前价格
            }
        }
        return sell[2];
    }
};
