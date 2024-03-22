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
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int start = 0, end = 1;
        int min_jump_cnt = 0;
        while (end < n) {
            int maxPos = 0;
            for (int i = start; i < end; i++) // end一定小于n因此不需要判断i<n
            {
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end;
            end = maxPos + 1; //前闭后开
            ++min_jump_cnt;
        }
        return min_jump_cnt;

    }
};
