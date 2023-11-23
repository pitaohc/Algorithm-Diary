#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto write_it = nums.begin(), read_it = nums.begin();
        while (read_it != nums.end())
        {
            if (*read_it != val) {
                *write_it = *read_it;
                ++write_it;
            }
            ++read_it;
        }
        return static_cast<int>(write_it - nums.begin());
    }
};

