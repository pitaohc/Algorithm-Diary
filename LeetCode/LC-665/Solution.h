#pragma once
#include"stdc++.h"

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        using namespace std;
        int result = 0, n = nums.size();
        for (size_t i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                result++;
                if (result > 1) return false;
                if (i == 1 || nums[i] >= nums[i - 2])
                {
                    nums[i - 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
            }

        }

        return true;
    }
};