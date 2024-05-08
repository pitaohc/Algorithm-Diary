#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-931.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<vector<int>> matrix, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    for (const auto& line : matrix) {
        fmt::print("{}\n", line);
    }
    auto res = sol.minFallingPathSum(matrix);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL!!!\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Returned: {}\n", res);
    }

}
int main() {
    test({ {2,1,3},{6,5,4},{7,8,9} }, 13);
    test({ {-19,57},{-40,-5} }, -59);
    test({ {0} }, 0);
    test({ { 1,1,1} }, 1);
    test({ {1},{1},{1} }, 3);
    return 0;
}
