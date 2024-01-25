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
    vector<int> ancients;
    int find(int node) {
        if (ancients[node] == node) {
            return node;
        }
        return ancients[node] = find(ancients[node]);
    }
    void merge(int node1, int node2) {
        int a1 = find(node1), a2 = find(node2);
        if (a1 != a2) {
            ancients[a2] = a1;
        }
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        ancients.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            ancients[i] = i;
        }

        vector<int> parents(n + 1);
        for (int i = 1; i <= n; ++i) {
            parents[i] = i;
        }

        int conflict = -1; // 冲突标记
        int cycle = -1; //环路标记

        for (int i = 0; i < n; ++i) { // 遍历每条边
            int node1 = edges[i][0], node2 = edges[i][1];
            if (parents[node2] != node2) {
                conflict = i;// node2出度大于1，标记冲突边
            }
            else {
                parents[node2] = node1;
                if (find(node1) == find(node2)) {
                    //新边导致环路
                    cycle = i;
                }
                else {
                    merge(node1, node2);
                }
            }
        }
        vector<int> res;
        if (conflict < 0) { // 没有发生冲突，产生了环路
            res = { edges[cycle][0],edges[cycle][1] };
        }
        else {
            const auto& conflictEdge = edges[conflict];
            if (cycle >= 0) { // 冲突导致了环路
                res = { parents[conflictEdge[1]],conflictEdge[1] };
            }
            else {
                res = conflictEdge;
            }
        }
        return res;
    }
};

