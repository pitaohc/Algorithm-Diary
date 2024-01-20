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
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int n = quiet.size();
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& edge : richer) {
            graph[edge[1]].emplace_back(edge[0]);
        }
        vector<int> res(n);
        vector<uint8_t> visited(n, false);
        for (int i = 0; i < n; ++i) {
            res[i] = i;
        }

        function<void(int)> dfs = [&](int node) {
            int q = quiet[res[node]]; //标记当前最优值
            int p = res[node]; //标记当前最优节点

            for (auto& next : graph[node]) {
                if (!visited[next]) {
                    dfs(next);
                }
                if (q > quiet[next]) { // 更新最优值
                    q = quiet[next];
                    p = res[next];
                }
            }
            quiet[node] = q;
            res[node] = p;
            visited[node] = true;
        };
        for (int i = 0; i < n; ++i) {
            dfs(i);
        }
        return res;
    }
};

