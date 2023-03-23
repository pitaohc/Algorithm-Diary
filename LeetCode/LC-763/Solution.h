#pragma once
#include"stdc++.h"

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        using namespace std;
        vector<vector<int>> stat(26, vector<int>(2, -1));
        //转换成重叠区间问题
        for (size_t i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            int index = ch - 'a';
            if (stat[index][0] == -1)
            {
                stat[index][1] = stat[index][0] = i;
            }
            else
            {
                stat[index][1] = i;
            }
        }
        //按照区间左侧排序
        sort(stat.begin(), stat.end(), [](const auto& left, const auto& right)
            {
                return left[0] < right[0];
            });
        int left = -1, right = -1;
        vector<int> result;
        for (const auto& range : stat)
        {
            if (range[0] == -1) //不存在区间
            {
                continue;
            }

            if (left == -1)
            {
                left = range[0], right = range[1];
            }
            if (range[0] > right)
            {
                //没有交集
                result.push_back(right - left + 1);
                left = range[0];
                right = range[1];
            }
            else
            {
                left = min(left, range[0]);
                right = max(right, range[1]);
            }
        }
        result.push_back(right - left + 1);
        return result;
    }
};