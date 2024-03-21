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
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int max_pos = nums[0];
        for (int i = 0; i <= max_pos && i < n; i++)
        {
            max_pos = max(max_pos, i + nums[i]);
#ifdef _DEBUG
            fmt::print("pos {}: max_pos: {}\n", i, max_pos);
#endif // _DEBUG
            if (i == max_pos) { // 无法前进
                break;
            }
        }

        return max_pos >= n - 1;
    }
};