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
    vector<int> parents;
    int find(int id) {
        if (parents[id] != id) {
            parents[id] = find(parents[id]);
        }
        return parents[id];
    }

    void unionSets(int left, int right) {
        int ancientLeft = find(left);
        int ancientRight = find(right);
        parents[ancientRight] = ancientLeft;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        parents.resize(n+1);
        for (size_t i = 1; i <= n; i++)
        {
            parents[i] = i;
        }
        for (const auto& edge : edges) {
            int left = edge[0];
            int right = edge[1];
            if (find(left) != find(right)) {
                unionSets(left, right);
            }
            else {
                return edge;
            }
        }
        return {};
    }
}; 

