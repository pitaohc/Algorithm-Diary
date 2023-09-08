#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-51.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    int n;
    vector<vector<string>> res, ans;


    //n = 1;
    //fmt::print("Case {}\n", caseNum++);
    //fmt::print("n = {}\n", n);
    //res = sol.solveNQueens(n);
    //fmt::print("res:\n"
    //    "{}\n", res);

    n = 4;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("n = {}\n", n);
    res = sol.solveNQueens(n);
    fmt::print("res:\n"
        "{}\n", res);

    return 0;
}
