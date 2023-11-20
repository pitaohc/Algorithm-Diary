#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& left, const auto& right)->bool {
            if (left[1] == right[1])
                return left[0] < right[0];
            else
                return left[1] > right[1];
             });

#ifdef _DEBUG
        fmt::print("sorted: {}\n", intervals);
#endif
        vector<vector<int>> result;
        int cur_b= intervals[0][0], cur_e = intervals[0][1];
        for (const auto& interval : intervals) {
            if (cur_b<= interval[0] && interval[0] <= cur_e ||
                cur_b<= interval[1] && interval[1] <= cur_e) { //���������Ŀ�ʼλ��С�ڵ��ڵ�ǰ�Ľ���λ�ã���������
                cur_b = min(cur_b, interval[0]);
                cur_e = max(cur_e, interval[1]);
            }
            else { //���û���ص����򣬷���������������
                result.push_back({ cur_b,cur_e });
                cur_b = interval[0];
                cur_e = interval[1];
            }
        }
        result.push_back({ cur_b,cur_e }); //�������һ������
        return result;
    }
};
