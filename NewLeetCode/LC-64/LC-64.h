#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                int& temp = grid[x][y];
                if (x > 0 && y > 0) //将命中数量最多的分支放在前面
                {
                    temp += min(grid[x - 1][y], grid[x][y - 1]);
                }
                else if (x == 0 && y > 0)
                {
                    temp += grid[0][y - 1];
                }
                else if (x > 0 && y == 0)
                {
                    temp += grid[x - 1][0];
                }
            }
        }
        return grid[n - 1][m - 1];
    }
};
