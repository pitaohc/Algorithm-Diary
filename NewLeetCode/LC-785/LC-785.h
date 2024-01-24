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
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        if (n == 0) { return true; }
        vector<int> color(graph.size(), 0);
        queue<int> visit;
        for (int i = 0; i < n; ++i) {
            //遍历每个顶点

            //判断染色状态
            // 0 未染色，默认染成 1
            // 1 已经染色，
            // 2 已经染色
            if (color[i] == 0) {
                color[i] = 1;
                visit.push(i);
            }
            
            while (!visit.empty()) {
                int node = visit.front(); visit.pop();

                for (const int j : graph[node]) {
                    int& c = color[j];
                    if (c == 0) {
                        c = (color[node] == 2) ? 1 : 2;
                        visit.push(j);
                    }
                    else if (c == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};