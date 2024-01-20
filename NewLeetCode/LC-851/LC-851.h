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
        vector<int> res(n,-1);
#ifdef _DEBUG
        fmt::print("Graph: \n"
            "{}\n", graph);
#endif // _DEBUG

        function<void(int)> dfs = [&](int node) {
            int q = quiet[node]; //标记当前最优值
            int p = node; //标记当前最优节点

            for (auto& next : graph[node]) {
                if (res[next] == -1) {
                    dfs(next);
                }
                if (q > quiet[next]) { // 更新最优值
                    q = quiet[next];
                    p = res[next];
                }
            }
            quiet[node] = q;
            res[node] = p;
#ifdef _DEBUG
            fmt::print("{} quiet: {}, res: {}\n", node, quiet[node], res[node]);
#endif // _DEBUG

        };
        for (int i = 0; i < n; ++i) {
            if (res[i] == -1)
            {
                dfs(i);
            }
        }
        return res;
    }
};

