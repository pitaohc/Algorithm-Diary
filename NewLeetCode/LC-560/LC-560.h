#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        int result = 0;
        unordered_map<int, int> um;
        int sum = 0;
        um[0] = 1; //当从开头选取到当前时，需要减去0
        for (int num : nums) {
            sum += num;
            result += um[sum - k];
            ++um[sum];
        }
        return result;
    }
};
