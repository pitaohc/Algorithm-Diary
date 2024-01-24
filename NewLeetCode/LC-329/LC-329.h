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
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int n = matrix.size(),m = matrix[0].size();
        int maxPath = 0;
        vector<vector<int>> status(n,vector<int>(m,0));
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if (status[x][y] > 0) {
                return status[x][y];
            }
            const static vector<vector<int>> directions = { {0,1},{1,0},{0,-1},{-1,0} };
            int curMaxPath = 0;
            for (const auto& direction : directions) {
                int nx = x + direction[0];
                int ny = y + direction[1];
                if (nx<0 || nx>=n || ny<0 || ny>=m) {
                    continue;
                }
                if (matrix[nx][ny] > matrix[x][y]) {
                    curMaxPath = max(curMaxPath, dfs(nx, ny));
                }
            }
            ++curMaxPath;
            maxPath = max(maxPath, curMaxPath);
            return status[x][y] = curMaxPath;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i, j);
            }
        }
        return maxPath;
    }
};
