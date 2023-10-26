#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1, 0);
        vector<int> temp(m + 1, 0);
        for (size_t i = 0; i <= m; i++)
        {
            //第一行， word1相当于空字符串，所有word2中的字符都需要插入
            dp[i] = i;
        }
        for (size_t i = 1; i <= n; i++)
        {
            temp[0] = i; // word2为空串的情况，所有word1中的字符都需要删除
            for (size_t j = 1; j <= m; j++)
            {
                temp[j] = min({
                    dp[j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1), //判断当前的字符是否相等，如果不等则需要替换
                    dp[j] + 1, //插入字符
                    temp[j - 1] + 1 }); //删除字符
            }
            dp = temp; //保存当前行
        }
        return dp[m];
    }
};
