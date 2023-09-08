#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<functional>
using namespace std;
class Solution {

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int l = word.size();
        if (l > m * n) return false;
        vector<vector<bool>> visited(m, vector<bool>(n)); // true 已经访问, false 未访问

        function<bool(int, int, int)> dfs = [&](int x, int y, int pos)-> bool {
            if (pos >= l - 1)
            {
#ifdef DEBUG
                fmt::print("SUCCEED ({},{}) = [{}]{}\n", x, y, pos, word[pos]);
#endif // DEBUG

                return true;
            }

            static vector<vector<short>> directions = { {0,1},{1,0},{-1,0},{0,-1} };
#ifdef DEBUG
            fmt::print("Inter ({},{}) = [{}]{}\n", x, y, pos, word[pos]);
#endif // DEBUG

            visited[x][y] = true; //标记访问
            for (const auto& direction : directions) {
                int nx = x + direction[0], ny = y + direction[1]; //下一步格子
                if (nx >= m || nx < 0 || ny >= n || ny < 0) continue; //新位置不合法

                if (visited[nx][ny]) continue; //已经访问过



                if (board[nx][ny] == word[pos + 1]) { //如果字符相同
                    bool result = dfs(nx, ny, pos + 1);
                    if (result) {
                        visited[x][y] = false; //回退
#ifdef DEBUG
                        fmt::print("SUCCEED ({},{}) = [{}]{}\n", x, y, pos, word[pos]);
#endif // DEBUG

                        return true;
                    }
                }
                else { //如果字符不同
                    continue;
                }

            }
            visited[x][y] = false; //取消标记访问

#ifdef DEBUG
            fmt::print("Exit ({},{}) = [{}]{}\n", x, y, pos, word[pos]);
#endif // DEBUG
            return false;
        };

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    bool result = dfs(i, j, 0);
                    if (result)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};