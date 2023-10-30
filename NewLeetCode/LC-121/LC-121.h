#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;

        int begin = 0;
        for (int end = 1; end < prices.size(); ++end)
        {
            if (prices[end] < prices[begin])
            {
                begin = end;
                continue;
            }
            result = max(result, prices[end] - prices[begin]);

        }

        return result;
    }
};