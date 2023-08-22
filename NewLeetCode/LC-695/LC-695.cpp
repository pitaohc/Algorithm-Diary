//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-695-Solution.h"
using namespace std;

int main() {
    Solution sol;
    int caseNum, res, ans;
    vector<vector<int>> grid;

    caseNum = 1;
    grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
    ans = 6;
    fmt::print("Case {}\n"
        "map: \n"
        "{}\n"
        "ans = {}, ",
        caseNum,
        grid,
        ans);
    res = sol.maxAreaOfIsland(grid);
    fmt::print("res = {}\n", res);
    cout << endl;

    caseNum = 2;
    grid = { {1
        } };
    ans = 1;
    fmt::print("Case {}\n"
        "map: \n"
        "{}\n"
        "ans = {}, ",
        caseNum,
        grid,
        ans);
    res = sol.maxAreaOfIsland(grid);
    fmt::print("res = {}\n", res);
    cout << endl;

    caseNum = 3;
    grid = { {0,0,0
        } };
    ans = 0;
    fmt::print("Case {}\n"
        "map: \n"
        "{}\n"
        "ans = {}, ",
        caseNum,
        grid,
        ans);
    res = sol.maxAreaOfIsland(grid);
    fmt::print("res = {}\n", res);
    cout << endl;

    caseNum = 4;
    grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1} };
    ans = 4;
    fmt::print("Case {}\n"
        "map: \n"
        "{}\n"
        "ans = {}, ",
        caseNum,
        grid,
        ans);
    res = sol.maxAreaOfIsland(grid);
    fmt::print("res = {}\n", res);
    cout << endl;

    return 0;
}