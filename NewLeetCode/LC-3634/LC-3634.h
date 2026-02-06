#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;

class Solution
{
public:
    int minRemoval(vector<int>& nums, int k)
    {
        int n = nums.size();
        int res = n -1; // 至少剩下一个元素
        if (n <= 1) return 0;
        sort(nums.begin(), nums.end());
#ifdef _DEBUG
        fmt::println("sorted: {}", nums);
#endif
        auto left = nums.begin();
        auto right = nums.begin();
        while (left < nums.end() && right<nums.end())
        {
            long long int target = static_cast<long long int>(*left) * k;
#ifdef _DEBUG
            fmt::println("target: {}",target);
#endif
            // 向右搜索，直到无下个元素或者下个元素大于目标
            while (right < nums.end() - 1  && *(right +1) <= target)
            {
                ++right;
            }

#ifdef _DEBUG
                fmt::println("left: {}, right: {}, cur: {},res: {}",
                    left - nums.begin(),
                    right - nums.begin(),
                    n - static_cast<int>(right - left + 1),
                    res
                    );
#endif
                res = min(res,n - static_cast<int>(right - left + 1));

            ++left;
        }
        return res;
    }
};
