#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        const int n = nums.size();
        for (const int num : nums) {
            int index = abs(num % n); //n存放在0上，当前遍历到的数字可能已经被置为负数
            if (nums[index] > 0) //判断是否已经统计过
            {
                nums[index] = -nums[index];
            }
#ifdef _DEBUG
            fmt::print("DEBUG: num = {}, nums = {}\n",num, nums);
#endif

        }
#ifdef _DEBUG
        fmt::print("DEBUG: {}\n", nums);
#endif
        for (int i = 1; i <= n; i++) {
            if (nums[i % n] > 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};