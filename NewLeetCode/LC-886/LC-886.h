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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<uint8_t> color(n + 1);
        for (const auto& edge : dislikes) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        queue<int> q;
        constexpr uint8_t UNVISITED = 0;
        constexpr uint8_t FULL = 0b11;


        for (int i = 1; i <= n; ++i) {
            if (color[i] != UNVISITED) {
                continue;
            }
            color[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (const auto& next : graph[node]) {
                    if (color[next] == UNVISITED) {
                        color[next] = FULL ^ color[node];
                        q.push(next);
                    }
                    else if (color[next] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

