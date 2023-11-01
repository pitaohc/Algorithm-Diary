#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-64.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> grid;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    grid = {
        {1,3,1,},
        {1,5,1,},
        {4,2,1,},
    };
    ans = 7;
    res = sol.minPathSum(grid);
    for (auto& col : grid)
    {
        fmt::print("{}\n", col);
    }
    fmt::print("ans = {}, res = {}\n", ans, res);
    return 0;
}
