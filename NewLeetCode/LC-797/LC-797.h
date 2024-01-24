#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> stk;
    int n;
    void dfs(vector<vector<int>>& graph, int node) {
        if (node == n - 1) {
            res.push_back(stk);
            return;
        }

        for (auto& to : graph[node]) {
            stk.push_back(to);
            dfs(graph, to);
            stk.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        stk.push_back(0);
        dfs(graph, 0);
        return res;
    }
};

