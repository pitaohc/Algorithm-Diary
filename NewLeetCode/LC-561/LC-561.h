#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        int result = 0;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2) {
            result += nums[i];
        }
        return result;
    }
};
