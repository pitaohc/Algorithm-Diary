#pragma once
#include"stdc++.h"

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        using namespace std;
        int result = 1;
        sort(points.begin(), points.end(), [](const auto& left, const auto& right) {
            return left[0] < right[0];
            });
        int right = points[0][1];
        for (const auto& point : points)
        {
            if (point[0] > right)
            {
                result++;
                right = point[1];
            }
            else
            {
                right = min(right, point[1]);
            }
        }
        return result;
    }
};