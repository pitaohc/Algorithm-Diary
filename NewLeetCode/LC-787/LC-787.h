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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        constexpr int INF = INT_MAX / 2;
        vector<int> dist(n, INF);
        dist[src] = 0;
        int minCost = INF;
        for (int turn = 1; turn <= k + 1; ++turn) {
            vector<int> newDist(n, INF);
            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], cost = flight[2];
                newDist[to] = min(newDist[to], dist[from] + cost);
            }
            dist = move(newDist);
            minCost = min(minCost, dist[dst]);
        }
        return minCost != INF ? minCost : -1;
    }
};
