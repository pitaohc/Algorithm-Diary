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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return { 0 };
        }
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        vector<int> res;
        //构建无向邻接表
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        queue<int> q;
        //寻找度为1的节点
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);

            }
        }
        int remainNodes = n;
        while (remainNodes > 2) {
#ifdef _DEBUG
            fmt::print("level: {}\n", q);
#endif // _DEBUG
            remainNodes -= q.size();
            //遍历当前层
            for (int size = q.size(); size > 0; --size) {
                int node = q.front();
                q.pop();

                for (int next : graph[node]) {
                    --degree[next];
                    if (degree[next] == 1) {
                        q.push(next);
                    }
                }
            }

        }
        res.reserve(q.size());
        while (!q.empty()) {
            res.emplace_back(q.front());
            q.pop();
        }
        return res;
    }
};

