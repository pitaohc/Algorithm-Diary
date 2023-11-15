#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int num : nums)
        {
            ++um[num];
        }
        int result = 0;
        for (const auto& [n, c] : um)
        {
            if (c == 1)
            {
                result = n;
                break;
            }
        }
        return result;
    }
};
