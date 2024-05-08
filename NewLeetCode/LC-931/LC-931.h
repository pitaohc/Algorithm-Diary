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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        vector<int> dp(matrix[0]);
#ifdef _DEBUG
        fmt::print("{}\n", dp);
#endif // _DEBUG

        for (int i = 1; i < n; i++)
        {
            vector<int> new_dp(m, 0);
            for (int j = 0; j < m; j++)
            {
                auto it1 = dp.begin() + max(j - 1, 0);
                auto it2 = dp.begin() + min(j + 1, m - 1) + 1;
                new_dp[j] = matrix[i][j] + *min_element(it1, it2);
            }
            dp = std::move(new_dp);
#ifdef _DEBUG
            fmt::print("{}\n", dp);
#endif // _DEBUG
        }


        return *min_element(dp.begin(), dp.end());
    }
};
