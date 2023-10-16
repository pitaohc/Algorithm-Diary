#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[3] = { 0,1,0 }; //f[i-2],f[i-1],f[i]
        int a = 0, b = 1, c = 0;
        for (size_t i = 1; i <= n; i++)
        {
            c = 0;
            if (s[i - 1] != '0')
            {
                //可以单个字母，前一个字母不为0
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
            {
                //两个字母组合
                c += a;
            }
            a = b;
            b = c;
        }
        return c;
    }
};
