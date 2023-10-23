#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 排除长度为1
        if (nums.size() < 2) 
        {
            return false;
        }
        int n = nums.size(), target, max_num;
        target = accumulate(nums.begin(), nums.end(), 0);
        max_num = *max_element(nums.begin(), nums.end());
        if (target % 2 == 1)
        {
            return false;
        }
        target = target / 2;
        if (target < max_num)
        {
            return false;
        }
        vector<bool> dp(vector<bool>(target + 1, false));
        dp[0] = true;
        dp[nums[0]] = true; //只选取第一个物品
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }
            if (dp[target])
            {
                return true;
            }
        }
        return dp[target];
    }
};