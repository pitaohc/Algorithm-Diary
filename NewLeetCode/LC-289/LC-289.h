#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
// 中文
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int n = board.size();
        const int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        
                        if (di == 0 && dj == 0) {
                            continue;
                        }
                        const int newi = i + di;
                        const int newj = j + dj;
                        if (newi >= 0 && newi < n && newj >= 0 && newj < m) {
                            board[newi][newj] += 8 * (board[i][j] % 8);
                        }
                    }
                }
            }
        }
#ifdef _DEBUG
        fmt::print("DEBUG\n");
        for (const auto& t : board) {
            fmt::print("{}\n", t);
        }
#endif // _DEBUG
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int around = board[i][j] / 8;
                int cur = board[i][j] % 8;
                if (around == 2) {
                    board[i][j] = cur;
                }
                else if (around == 3) {
                    board[i][j] = 1;
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
#ifdef _DEBUG
        fmt::print("DEBUG\n");
        for (const auto& t : board) {
            fmt::print("{}\n", t);
        }
#endif // _DEBUG
    }
};

