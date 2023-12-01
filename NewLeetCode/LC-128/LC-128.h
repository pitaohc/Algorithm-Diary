#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int result = 0;
        for (int num : nums) {
            us.insert(num);
        }
        while (!us.empty())
        {
            int curNum = *us.begin();
            us.erase(curNum);
            int prev = curNum - 1, next = curNum + 1;
            while (us.count(prev))
            {
                us.erase(prev--);
            }
            while (us.count(next))
            {
                us.erase(next++);
            }
            result = max(result, next - prev - 1); // 开区间
        }
        return result;
    }
};

