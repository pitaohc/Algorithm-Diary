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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        int cnt = 0;
        vector<int> visited(n);
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            const int node = q.front();
            q.pop();
            if (visited[node]) {
                continue;
            }
#ifdef _DEBUG
            fmt::print("visit {}\n", node);
#endif // _DEBUG

            visited[node] = true;
            ++cnt;
            for (const auto& to : rooms[node]) {
                if (!visited[to]) {
                    q.push(to);
                }
            }
        }
#ifdef _DEBUG
        fmt::print("n = {}, cnt = {}\n", n, cnt);
#endif // _DEBUG

        return cnt == n;
    }
};

