#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<int> result;
        unordered_map<int, int> um;

        for (int i = 0; i < n; ++i) {
            auto it = um.find(target - nums[i]);
            if (it != um.end()) {
                result = { i,it->second };
                break;
            }
            else {
                um.insert({ nums[i],i });
            }
        }
        return result;
    }
};
