#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<fmt/ranges.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp;
        dp.reserve(n / 2); //提前开辟空间，避免vector容量增长导致的多次复制
        dp.emplace_back(nums[0]);
#ifdef _DEBUG
        fmt::print("{}\n", dp);
#endif // _DEBUG
        for (size_t i = 1; i < n; i++)
        {
            if (dp.back() < nums[i]) {
                dp.emplace_back(nums[i]);
#ifdef _DEBUG
                fmt::print("{}\n", dp);
#endif // _DEBUG
            }
            else {
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i]; //更新数字
            }
        }
#ifdef _DEBUG
        fmt::print("{}\n", dp);
#endif // _DEBUG
        return dp.size();
    }
};

