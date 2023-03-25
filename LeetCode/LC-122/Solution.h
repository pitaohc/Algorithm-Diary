#pragma once
#include"stdc++.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            if (prices[i - 1] < prices[i]) //要是第二天价格比前一天高，就在前一天买进
            {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};