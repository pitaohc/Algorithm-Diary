#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
private:
    using LL = long long;
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        // 1. 修改背包容量
        LL backage = speed * hoursBefore;
        // 2. 检查是否无法到达
        for (int& w : dist) {
            backage -= w;
        }
        if (backage < 0) {
            return -1;
        }

        // 3. dp
        backage = speed * hoursBefore;
        const int n = dist.size();
        vector<vector<LL>> dp(n + 1, vector<LL>(n + 1, LLONG_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j != i) {
                    dp[i][j] = min(dp[i][j],
                        ((dp[i - 1][j] + dist[i - 1] - 1) / speed + 1) * speed);
                }
                if (j != 0) {
                    dp[i][j] = min(dp[i][j],
                        dp[i - 1][j - 1] + dist[i - 1]);
                }
            }
        }
        for (size_t j = 0; j <= n; j++)
        {
            if (dp[n][j] <= backage) {
                return j;
            }
        }
        return -1;
    }
};

