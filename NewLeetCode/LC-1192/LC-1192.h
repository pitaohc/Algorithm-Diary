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
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (const auto& edge : connections) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }


        vector<vector<int>> result;
        vector<int> times(n);
        vector<int> lows(n);
        int num = 0;
#ifdef _DEBUG
        for (int i = 0; i < n; ++i) {
            fmt::print("node {}: {}\n", i, graph[i]);
        }
#endif // _DEBUG

        function<void(int node, int prev)> dfs = [&](int node, int prev) {
            lows[node] = times[node] = ++num; //时间戳自增


            for (int next : graph[node]) { //遍历相邻节点
                if (times[next] == 0) { //如果next没有被访问过
                    dfs(next, node);
                    lows[node] = min(lows[node], lows[next]);
                    if (lows[next] > times[node]) { // 发现桥边，添加到结果
                        result.push_back({ node,next });
                    }
                }
                else if (times[next] < times[node] && next != prev) { // // v 已经在 u 之前被访问过了。因为是无向图，u 可以反向访问到其 【dfs搜索树】上的父节点，此时需要跳过。
                    lows[node] = min(lows[node], lows[next]);
                }
            }
#ifdef _DEBUG
            fmt::print("node {}, low {}, time {}\n", node, lows[node], times[node]);
#endif // _DEBUG
            };
        dfs(0, 0);
        return result;
    }
};

