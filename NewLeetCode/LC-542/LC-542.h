#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX - 1));
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < m; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); //从左边移动而来
                    }
                    if (j > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); //从上边移动而来
                    }
                }
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i < n - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1); //从右边移动而来
                    }
                    if (j < m - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1); //从下边移动而来
                    }
                }
            }
        }
        return dp;
    }
};