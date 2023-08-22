//
// Created by devcpp on 23-8-15.
//

#ifndef LC_695_SOLUTION_H
#define LC_695_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    int areaOfIsland(vector<vector<int>>& grid, int x, int y) {
        int area = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> que;
        que.push({ x,y });
        grid[x][y] = 0;
        while (!que.empty()) {
            auto point = que.front();

            ++area;

            que.pop();

            if (point.first > 0 && grid[point.first - 1][point.second]) {
                //向上
                que.push({ point.first - 1,point.second });
                grid[point.first - 1][point.second] = 0;
            }
            if (point.second > 0 && grid[point.first][point.second - 1]) {
                //向左
                que.push({ point.first,point.second - 1 });
                grid[point.first][point.second - 1] = 0;
            }
            if (point.first < n - 1 && grid[point.first + 1][point.second]) {
                //向下
                que.push({ point.first + 1,point.second });
                grid[point.first + 1][point.second] = 0;
            }
            if (point.second < m - 1 && grid[point.first][point.second + 1]) {
                //向右
                que.push({ point.first ,point.second + 1 });
                grid[point.first][point.second + 1] = 0;
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, areaOfIsland(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
#endif //LC_695_SOLUTION_H
