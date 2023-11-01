#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<bitset>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (size_t i = 2; i <= m; i++)
        {
            if (p[i - 1] == '*') //如果前一个字符是匹配零个或多个前面的那一个元素
            {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (size_t i = 1; i <= n; i++)
        {
            char& chs = s[i - 1];
            for (size_t j = 1; j <= m; j++)
            {
                char& chp = p[j - 1];
                if (chs == chp || chp == '.') //如果最后一个字符相同，或者模式串最后字符是'.'
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (chp == '*') //如果模式串最后一个字符是'*'
                {
                    char& chreal = p[j - 2];
                    if (chs == chreal || chreal == '.')
                    {
                        //需要考虑三种情况，匹配0个，匹配1个，匹配多个
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[n][m];
    }
};