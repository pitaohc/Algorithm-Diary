#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    pair<int, int> count(const string& str)
    {
        int n = 0;
        for (const auto& ch : str)
        {
            if (ch == '0')
            {
                ++n;
            }
        }
        return { n,str.size() - n };
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto& str : strs)
        {
            auto [count0, count1] = this->count(str);
            for (int i = m; i >= count0; i--) //因为压缩数组为二维，所以更新dp数组时需要反向遍历
            {
                for (int j = n; j >= count1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};