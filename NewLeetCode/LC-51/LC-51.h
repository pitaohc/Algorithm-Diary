#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<functional>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> row(n, false), leftup(n * 2 - 1, false), rightup(n * 2 - 1, false);
        vector<string> chessboard = vector<string>(n, string(n, '.'));
        vector<vector<string>> res;
        auto check = [&](int x, int y)->bool {
            return row[x] || leftup[x - y + n - 1] || rightup[x + y];
        };
        auto modify = [&](int x, int y, bool status) {
            row[x] = leftup[x - y + n - 1] = rightup[x + y] = status;
            if (status) {
                chessboard[x][y] = 'Q';
            }
            else {
                chessboard[x][y] = '.';
            }
        };
        function<void(int, int)> dfs = [&](int x, int y) {
#ifdef DEBUG
            fmt::print("Enter ({},{})\n", x, y);
#endif
            modify(x, y, true);
            if (y >= n - 1) {
                res.emplace_back(chessboard);
#ifdef DEBUG
                fmt::print("SUCCESS ({},{})\n", x, y);
#endif
                modify(x, y, false);
                return;
            }
            for (size_t i = 0; i < n; i++)
            {
                if (check(i, y + 1)) continue;

                dfs(i, y + 1);
            }
            modify(x, y, false);
#ifdef DEBUG
            fmt::print("Exit ({},{})\n", x, y);
#endif

        };



        for (size_t i = 0; i < n; i++) //遍历每行
        {
            dfs(i, 0);
        }
        return res;
    }
};

