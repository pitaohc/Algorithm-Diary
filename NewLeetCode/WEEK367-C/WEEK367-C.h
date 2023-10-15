#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        int mmin = INT_MAX, mmax = INT_MIN;
        map<int, int> mp;
        for (size_t i = 0; i < n; i++)
        {
            mmin = min(mmin, nums[i]);
            mmax = max(mmax, nums[i]);
            if (i >= indexDifference)
            {
                mp[nums[i]]++;
            }
        }
        if (mmax - mmin < valueDifference)
        {
            return { -1,-1 };
        }
        for (int i = 0; i < n - indexDifference; i++)
        {
            int num1 = nums[i];
            int num2 = mp.begin()->first; //最小值
            if (abs(num1 - num2) >= valueDifference)
            {
                //寻找num2
                for (int j = i + indexDifference; j < n; j++)
                {
                    if (nums[j] == num2) {
                        return { i,j };
                    }
                }
            }
            num2 = (--mp.end())->first; //最大值
            if (abs(num1 - num2) >= valueDifference)
            {
                //寻找num2
                for (int j = i + indexDifference; j < n; j++)
                {
                    if (nums[j] == num2) {
                        return { i,j };
                    }
                }
            }

            //不存在，排除区级第一个数字
            mp[nums[i + indexDifference]]--;
            if (mp[nums[i + indexDifference]] == 0) {
                mp.erase(nums[i + indexDifference]);
            }
        }

        return { -1,-1 };
    }
};