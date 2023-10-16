#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(4);
        dp[3] = 1;
        int len = 2;
        int diff = nums[1] - nums[0];
        int result = 0;
        for (size_t i = 2; i < n; ++i) {

            int current_diff = nums[i] - nums[i - 1];
            if (current_diff == diff) { //依然还是等差数列
                ++len;
                if (len >= dp.size()) {
                    dp.emplace_back(dp[dp.size() - 1] + len - 2);
                }
            }
            else { //非等差数列
                result += dp[len];
                len = 2;
                diff = nums[i] - nums[i - 1];
            }

        }
        return result + dp[len];
    }
};
