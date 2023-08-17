//
// Created by devcpp on 23-8-15.
//

#ifndef LC_540_SOLUTION_H
#define LC_540_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
#include<queue>
#include<map>
#include<utility>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const int& num : nums)
        {
            m[num]++;
        }

        auto cmp = [](const pair<int, int>& left, const pair<int, int>& right)-> bool {
            return (left.second == right.second) ? left.first < right.first : left.second < right.second;
        };

        priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (const auto& elem : m) {
            pq.push(elem);
        }
        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
#endif //LC_540_SOLUTION_H
