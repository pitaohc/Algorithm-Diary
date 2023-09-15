#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<functional>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<char>> marked(n, vector<char>(m, 'X'));


        function<void(int x, int y)> dfs = [&](int x, int y) {
            const static vector<pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1,0} };

            //保证当前节点为O，且还未访问过
            marked[x][y] = 'O';

            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //越界

                if (board[nx][ny] == 'O' && marked[nx][ny] != 'O') {
                    dfs(nx, ny);
                }
            }

        };
        //遍历左右两边
        for (size_t i = 0; i < n; i++)
        {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][m - 1] == 'O') dfs(i, m - 1);
        }
        //遍历上下两边
        for (size_t i = 0; i < m; i++)
        {
            if (board[0][i] == 'O') dfs(0, i);
            if (board[n - 1][i] == 'O') dfs(n - 1, i);
        }

        board = marked;

    }
};