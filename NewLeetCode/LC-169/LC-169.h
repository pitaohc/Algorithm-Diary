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
    int majorityElement(vector<int>& nums) {

        int candidate = -1; // 众数
        int count = 0; // 众数的个数
        for (const int num : nums) {
            if (num == candidate) { // 如果当前数等于众数，众数个数加一
                ++count;
            }
            else if (--count < 0) { // 如果众数的个数小于0，说明当前众数不是众数，更新众数
                candidate = num;
                count = 1;
            }
        }


        return candidate;
    }
};
