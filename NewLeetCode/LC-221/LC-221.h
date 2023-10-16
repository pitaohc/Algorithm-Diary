#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
        {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (size_t i = 0; i < n; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
        }
        for (size_t j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j] - '0';
        }
        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 1; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j],dp[i][j - 1] }) + 1;
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};