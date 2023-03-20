#pragma once
#include"stdc++.h"

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](const auto& left, const auto& right) {
            return left[1] < right[1];
            });

        int right = intervals[0][1];
        int result = 1;
        for (size_t i = 1; i < n; i++)
        {
            if (intervals[i][0] >= right)
            {
                ++result;
                right = intervals[i][1];
            }
        }
        return n - result;
    }
};