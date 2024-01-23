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
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> colors(n, 0);
        vector<vector<int>> graphs(n);
        for (const auto& path : paths) {
            graphs[path[0]-1].emplace_back(path[1]-1);
            graphs[path[1]-1].emplace_back(path[0]-1);
        }
        function<void(int)> dfs = [&](int node) {
            int status = 0;
            for (int neighbor : graphs[node]) {
                status |= (1 << colors[neighbor]);
            }
            //Ⱦɫ
            for (int i = 1; i <= 4; ++i) {
                if ((status & (1 << i)) == 0) {
                    colors[node] = i;
                    break;
                }
            }
            for (int neighbor : graphs[node]) {
                if (colors[neighbor] == 0) {
                    dfs(neighbor);
                }
            }

        };
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0) {
                dfs(i);
            }
        }
        return colors;
    }
};