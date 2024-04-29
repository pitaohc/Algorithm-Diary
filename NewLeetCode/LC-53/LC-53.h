#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> sums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        vector<int> mins(n + 1);
        int curmin = 0;
        for (int i = 1; i <= n; i++)
        {
            curmin = min(curmin, sums[i - 1]);
            mins[i] = curmin;
        }
        int res = nums[0];
        for (int i = 1; i <= n; i++)
        {
            res = max(res, sums[i] - mins[i]);
        }
        return res;
    }
};
