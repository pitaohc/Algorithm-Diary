#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        const int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        int left = 0;
        for (int middlePos = 0; middlePos < n; ++middlePos) {
            if (left == sum - left - nums[middlePos])
            {
                return middlePos;
            }
            left += nums[middlePos];
        }
        return -1;
    }
};

