#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 1);
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 2; j <= n; j++)
            {
                dp[j] = dp[j - 1] + dp[j];
            }
        }

        return dp[n];
    }
};

