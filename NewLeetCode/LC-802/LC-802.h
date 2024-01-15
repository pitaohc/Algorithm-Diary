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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> colors(n);
        function<bool(int)> safe = [&](const int x) {
            static constexpr int UNVISITED = 0;
            static constexpr int VISITING = 1;
            static constexpr int SAFE = 2;
            if (colors[x] != UNVISITED) {
                return colors[x] == SAFE;
            }
            colors[x] = VISITING;
            for (int y : graph[x]) {
                if (!safe(y)) { // lambda递归需要引用safe
                    return false;
                }
            }
            colors[x] = SAFE; // 所有出边都是安全的，标记当前节点为安全
            return true;
            };
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (safe(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

