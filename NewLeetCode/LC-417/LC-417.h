#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int x, int y) {
        const int n = heights.size(), m = heights[0].size();
        const static vector<pair<int, int>> directories = { {0,1},{1,0},{0,-1},{-1,0} }; // right,down,left,up
        if (ocean[x][y]) { //已经访问过的节点
            return;
        }
        ocean[x][y] = true; //访问当前点
        for (const auto& directory : directories) {
            int newX = x + directory.first, newY = y + directory.second;
            if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
            if (!ocean[newX][newY] && heights[newX][newY]>=heights[x][y]){
                //判断新的点是否已经访问过，并判断新的点是否高于等于当前点
                //判断是否已经访问过可以减小算法时间，因为调用函数比判断慢，可以避免不必要的调用
                dfs(heights, ocean, newX, newY);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> Pacific(n,vector<bool>(m)), Atlantic(n, vector<bool>(m));
        vector<vector<int>> result;

        for (int i = 0; i < n; i++)
        {
            dfs(heights, Pacific, i, 0);
            dfs(heights, Atlantic, i, m-1);

        }
        for (int j = 0; j < m; j++)
        {
            dfs(heights, Pacific, 0, j);
            dfs(heights, Atlantic, n-1, j);

        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Pacific[i][j] && Atlantic[i][j]) {
                    result.push_back({ i,j });
                }
            }
        }
        return result;
    }
};
