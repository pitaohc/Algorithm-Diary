#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> realnums(n + 2);
        realnums[0] = realnums[n + 1] = 1;
        copy(nums.begin(), nums.end(), realnums.begin() + 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2)); 
        //dp[i][j]以i开头，以j结束的闭区间中，最大的硬币数量
        //按长度遍历的原因是更长的区间依赖短区间的结果，所以先要遍历完短的区间
        for (int len = 2; len < n + 2; len++) //遍历长度
        {
            for (int left = 0; left + len< n+2; left++) //遍历左端点
            {
                int right = left + len; //设定右端点
                int tempMul = realnums[left] * realnums[right]; //暂存部分乘法答案
                for (int k = left+1; k < right; k++) //以k为分割点
                {
                    dp[left][right] = max(dp[left][right], dp[left][k] + dp[k][right] + tempMul * realnums[k]);
                    //取切割方法的最大值，dp[left][k]是左区间，dp[k][right]是右区间，tempMul * realnums[k]是当前分割方法需要增加的硬币
                }
            }
        }
        return dp[0][n + 1];
    }
};