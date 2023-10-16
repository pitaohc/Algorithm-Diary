#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-542.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> mat, res, ans;
    auto printMat = [](const vector<vector<int>>& mat) {
        for (const auto& col : mat)
        {
            fmt::print("{}\n", col);
        }
        };
    fmt::print("Case {}\n", caseNum++);
    mat = { {0,0,0},{0,1,0},{1,1,1} };
    ans = { {0,0,0},{0,1,0},{1,2,1} };
    res = sol.updateMatrix(mat);
    fmt::print("mat:\n");
    printMat(mat);
    fmt::print("ans:\n");
    printMat(ans);
    fmt::print("res:\n");
    printMat(res);

    return 0;
}
