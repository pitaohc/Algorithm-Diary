#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);
        //初始化第一种情况
        for (size_t i = 0; i <= amount; i += coins[0])
        {
            dp[i] = i / coins[0];
        }

        for (size_t i = 1; i < n; i++) //遍历硬币种类
        {
            // j<coins[i]
            //for (size_t j = 0; j < coins[i]; j++) //当前面额无法使用的情况
            //{
            //    continue;//继承上次的结果
            //}
            // coins[i]<=j<= k*coins[i]<=amount
            const int coin = coins[i];
            for (size_t j = coin; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }

        return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
    }
};