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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (const int& num : nums) {
            us.insert(num);
        }

        int result = 0;
        for (int num : us) {
            if (us.count(num - 1) == 0) { // num没有前序数字，是序列的开端
                int cur = 0;
                while (us.count(num))
                {
                    ++cur;
                    ++num;
                }
                result = max(result, cur);
            }
        }
        return result;

    }
};

