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
        vector<vector<int>> regraph(n, vector<int>());
        vector<int> outdegree(n, 0);
        for (int from = 0; from < n; ++from) {
            for (auto& to : graph[from]) {
                regraph[to].push_back(from);
                ++outdegree[from];
            }
        }
#ifdef _DEBUG
        fmt::print("regraph: {}\n"
            "indegree: {}\n", regraph,outdegree);
        
#endif // _DEBUG

        queue<int> q;
        vector<int> res;
        for (int node = 0; node < n; ++node) {
            if (outdegree[node] == 0) {
                q.push(node);
            }
        }
#ifdef _DEBUG
        fmt::print("init queue: {}\n", q);
#endif // _DEBUG

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (const auto& from : regraph[node]) {
                --outdegree[from];
                if (outdegree[from] == 0) {
                    q.push(from);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

