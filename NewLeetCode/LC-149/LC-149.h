#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> map; // 缺陷，double可能有精度问题，改设置精度+字符串保存
        int max_count = 0;
        for (auto it1 = points.begin(); it1 != points.end(); ++it1) {
            if (points.size() - (it1 - points.begin()) < max_count) { //如果剩余点的数量比目前的结果更少
                break;
            }
            int same = 1, same_x = 0; //same表示重复的点，same_x表示垂线上的点，不包括重复的点
            auto point1 = *it1;
            for (auto it2 = it1 + 1; it2 != points.end(); ++it2) {
                auto point2 = *it2;
                if (point1[0] == point2[0]) { //如果x坐标相同
                    if (point1[1] == point2[1]) { //如果是同一个点
                        ++same;
                    }
                    else {
                        ++same_x;
                    }
                }
                else
                {
                    double k = static_cast<double>(point2[1] - point1[1]) / static_cast<double>(point2[0] - point1[0]); //注意转换整形除法
                    ++map[k];
                }
            }
            max_count = max(max_count, same + same_x); //垂线上的点
            for (auto& [k, cnt] : map) {
                max_count = max(max_count, same + cnt);
            }
            map.clear();
        }
        return max_count;
    }
};

