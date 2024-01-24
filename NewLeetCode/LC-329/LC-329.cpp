#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-329.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<vector<int>> matrix,int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    int res = sol.longestIncreasingPath(matrix);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Got: {}\n", res);
    }
    cout << endl;
}
int main() {

    test({{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}, 4);
    test({{3, 4, 5}, {3, 2, 6}, {2, 2, 1}}, 4);
    test({ {1} }, 1);
    return 0;
}
