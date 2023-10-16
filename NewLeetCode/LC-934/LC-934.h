#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<fmt/ranges.h>
#include<fmt/color.h>

using namespace std;
class Solution {
private:
    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int x, int y) {
        const static vector<pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1,0} };
        stack<pair<int, int>> st;
        st.push({ x, y });
        points.push({ x,y });
        int n = grid.size(), m = grid[0].size();
        while (!st.empty()) {
            auto [x, y] = st.top();
            st.pop();
            grid[x][y] = 2;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if (grid[nx][ny] == 1) {
                    st.push({ nx,ny });
                    points.push({ nx,ny });
                }

            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const static vector<pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1,0} };
        int n = grid.size(), m = grid[0].size();
        bool finded = false;
        queue<pair<int, int>> points;
        for (size_t i = 0; i < n; i++)
        {
            if (finded) break;
            for (size_t j = 0; j < m; j++)
            {
                if (grid[i][j]) {
                    dfs(points, grid, i, j);
                    finded = true;
                    break;
                }
            }
        }
#ifdef DEBUG
        fmt::print(fmt::fg(fmt::color::forest_green), "修改后的地图\n");
        for (const auto& row : grid) {
            fmt::print("{}\n", row);
        }
#endif // DEBUG
        int level = 0;
        while (!points.empty()) {

            int size = points.size();
#ifdef DEBUG
            fmt::print("level {}, size {}:\n", level, size);
#endif 
            for (size_t i = 0; i < size; i++) //遍历当前层所有点
            {
                auto [x, y] = points.front();
#ifdef DEBUG
                fmt::print("{{{},{}}}, ", x, y);
#endif
                points.pop();
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    if (grid[nx][ny] == 1) {
#ifdef DEBUG
                        fmt::print("\n");
#endif
                        return level;
                    }
                    else if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        points.push({ nx,ny });
                    }
                }

            }
            level++;
#ifdef DEBUG
            fmt::print("\n");
#endif
        }

        return 0;
    }
};
