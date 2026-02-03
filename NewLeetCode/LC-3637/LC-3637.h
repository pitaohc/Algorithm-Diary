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
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n <=3) return false;
        // 检查每个阶段，并且判断是否至少比较了1次（有两个元素）
        int end = 0;
        bool check_flag = false;
        while (end < n-1 && nums[end] < nums[end + 1])
        {
            check_flag = true;
            ++end;
        }
#ifdef _DEBUG
        fmt::println("stage 1: {} {}",end,check_flag? "true":"false");
#endif
        if (!check_flag) return false;
        
        check_flag = false;
        while (end<n-1 && nums[end] > nums[end+1])
        {
            check_flag = true;
            ++end;
        }
#ifdef _DEBUG
        fmt::println("stage 2: {} {}",end,check_flag? "true":"false");
#endif
        if (!check_flag) return false;
        
        check_flag = false;
        while (end<n-1 && nums[end] < nums[end+1])
        {
            check_flag = true;
            ++end;
        }
#ifdef _DEBUG
        fmt::println("stage 3: {} {}",end,check_flag? "true":"false");
#endif
        if (!check_flag) return false;
        return end == n-1;
    }
};
