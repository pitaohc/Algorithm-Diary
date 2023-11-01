#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-221.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<char>> matrix;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    matrix = { {'1','1'},{'1','1'} };
    ans = 4;
    res = sol.maximalSquare(matrix);
    fmt::print(
        "matrix:\n"
        "{}\n"
        "ans = {}, res = {}\n", matrix, ans, res);
    return 0;
}
