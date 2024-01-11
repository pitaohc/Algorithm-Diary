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
        vector<vector<int>> dist(n, vector<int>(k + 2, INF));
        dist[src][0] = 0;
        for (int turn = 1; turn <= k + 1; ++turn) {
            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], cost = flight[2];
                dist[to][turn] = min(dist[to][turn], dist[from][turn - 1] + cost);
            }
        }
        int minCost = *min_element(dist[dst].begin(), dist[dst].end());
        return minCost != INF ? minCost : -1;
    }
};
