#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for (size_t i = 2; i <= n; i++)
        {
            dp[i] = i;
            for (size_t j = 2; j <= h; j++)
            {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i / j];
                    break; //减少循环次数
                }
            }
        }

        return dp[n];
    }
};