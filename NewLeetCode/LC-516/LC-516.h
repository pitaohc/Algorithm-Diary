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
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) // 以串的结尾位置作为外循环
        {
            dp[j][j] = 1; // 长度为1的串一定是回文字符串
            for (int i = j-1; i >=0; i--) // 注意遍历顺序，长的串依赖短的串，所以需要反向遍历
            {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 不相等的情况
                }
            }
        }
        return dp[0][n - 1];
    }
};
