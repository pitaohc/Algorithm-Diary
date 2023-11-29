#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        using pairii = pair<int, int>;
        auto cmp = [](const pairii& left, const pairii& right) -> bool {
            return left.second < right.second;
            };
        priority_queue<pairii, vector<pairii>, decltype(cmp)> pq(cmp); //使用lambda作为比较函数，需要在构造时传入实例，否则会导致调用已删除的函数
        vector<vector<int>> result;
        vector<int> boundaries;
        for (const auto& building : buildings) { //添加边缘
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end()); //对边缘排序
        int n = buildings.size(), idx = 0;
        for (const auto& boundary : boundaries) { //遍历可能的关键点横坐标(边缘)
            //添加新的建筑
            while (idx < n && buildings[idx][0] <= boundary) {
                pq.push({ buildings[idx][1],buildings[idx][2] });
                ++idx;
            }
            //删除已经结束的建筑
            while (!pq.empty() && pq.top().first <= boundary) {
                pq.pop();
            }
            int height = pq.empty() ? 0 : pq.top().second; //注意可能一栋建筑都没有
            if (result.empty() || height != result.back()[1]) {
                result.push_back({ boundary, height });
            }
        }
        return result;
    }
};

