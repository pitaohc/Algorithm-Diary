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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector < vector<int>> res;
        int i = 0;
        const int n = intervals.size();
        //特例判断
        if (n == 0) {
            res.push_back(newInterval);
            return res;
        }
        else if (newInterval[1] < intervals[0][0]) {
            //在区间最前端
            res = move(intervals);
            res.insert(res.begin(), newInterval);
            return res;
        }
        else if (newInterval[0] > intervals[n - 1][1]) {
            //在区间尾端
            res = move(intervals);
            res.insert(res.end(), newInterval);
            return res;
        }


        while (i<n && newInterval[0]> intervals[i][1]) {
            res.emplace_back(intervals[i]);
            ++i;
        }
        int rangeBegin = min(newInterval[0], intervals[i][0]);
#ifdef _DEBUG

        fmt::print("Find begin, cur id {}, cur range {}, new interval: {}, new begin {}\n",
            i, intervals[i], newInterval, rangeBegin);
#endif // _DEBUG
        while (i < n && newInterval[1] >= intervals[i][0]) {
            ++i;
        }
        --i;
        int rangeEnd = max(newInterval[1], intervals[i][1]);
#ifdef _DEBUG
        fmt::print("Find end, cur id {}, cur range {}, new interval: {}, new end {}\n",
            i, intervals[i], newInterval, rangeEnd);
#endif // _DEBUG
        res.push_back({ rangeBegin,rangeEnd });
        ++i;
        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};

