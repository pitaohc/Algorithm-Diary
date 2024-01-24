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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        constexpr int INF = INT_MAX / 2;
        //建立邻接矩阵
        vector<vector<int>> graph(n, vector<int>(n, INF));
        for (const auto& time : times) {
            int from = time[0] - 1, to = time[1] - 1;
            graph[from][to] = time[2];
        }
        vector<int> dist(n, INF);
        dist[k - 1] = 0;// 源节点距离为0
        vector<int8_t> used(n, false);
        //遍历节点
        for (int i = 0; i < n; ++i) {
            int node = -1;
            //找到未访问过的，且距离最近的节点
            for (int curNode = 0; curNode < n; ++curNode) {
                if (!used[curNode] && (node == -1 || dist[curNode] < dist[node])) {
                    node = curNode;
                }
            }
            used[node] = true; //标记访问
            //更新所有已访问过节点的距离
            for (int curNode = 0; curNode < n; ++curNode) {
                dist[curNode] = min(dist[curNode], dist[node] + graph[node][curNode]);
            }
#ifdef _DEBUG
            fmt::print("node {}\n"
                "dist: {}\n"
                "used: {}\n", node, dist, used);
#endif // _DEBUG

        }
        //找到最远的距离
        int maxTime = *max_element(dist.begin(), dist.end());
        return maxTime != INF ? maxTime : -1;
    }
};

