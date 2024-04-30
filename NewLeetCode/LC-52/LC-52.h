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
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<bool> cols(n), diagonal(2 * n - 1), antidiagonal(2 * n - 1);

        auto check = [&](const int x, const int y)->bool {
            return cols[y] || diagonal[x - y + n - 1] || antidiagonal[x + y];
            };
        auto modify = [&](const int x, const int y, const bool status) {
            cols[y] = diagonal[x - y + n - 1] = antidiagonal[x + y] = status;
            };
        function<void(int, int)> dfs = [&](const int x, const int y) {
            //保证下在[x,y]是正确的情况
            modify(x, y, true);
            if (x >= n - 1) {
                // 棋盘完全摆好
                ++res;
            }
            else {
                for (size_t i = 0; i < n; i++)
                {
                    if (!check(x + 1, i)) {
                        dfs(x + 1, i);
                    }
                }
            }

            modify(x, y, false);
            };

        for (size_t i = 0; i < n; i++)
        {
            dfs(0, i);
        }

        return res;
    }
};



