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
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, 0);
        result[0] = 1;

        for (int i = 1; i < n; i++)
        {

            result[i] = nums[i - 1] * result[i - 1];
        }
        int num = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            num *= nums[i + 1];
            result[i] *= num;
        }
        return result;
    }
};

