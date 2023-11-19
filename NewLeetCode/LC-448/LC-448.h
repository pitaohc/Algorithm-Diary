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

            int index = (num & 0x7FFFFFFF) % n; //n存放在0上
            bool flag = nums[index] & 0x80000000;
            if (!flag) //判断是否已经统计过
            {
                nums[index] = nums[index] | 0x80000000;
            }
#ifdef _DEBUG
            fmt::print("DEBUG: num = {}, nums = {}\n", num, nums);
#endif

        }
#ifdef _DEBUG
        fmt::print("DEBUG: {}\n", nums);
#endif
        for (int i = 1; i <= n; i++) {
            bool flag = nums[i % n] & 0x80000000;
            if (!flag) {
                result.push_back(i);
            }
        }
        return result;
    }
};