#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        auto begin_it = nums.begin(), end_it = nums.begin();
        int sum = 0;
        while (end_it != nums.end()) {
            sum += *end_it;
            while (sum>=target)
            {
                result = min(result, static_cast<int>(end_it - begin_it + 1));
                sum -= *begin_it;
                ++begin_it;

            }
            ++end_it;
        }

        return (result != INT_MAX) ? result : 0;
    }
};

