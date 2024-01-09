#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-207.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(int num, vector<vector<int>> prerequisites, bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fg(fmt::color::yellow), "Case {}\n", caseNum++);
    bool res = sol.canFinish(num, prerequisites);
    fmt::print("Input: num = {}, prerequisites = {}\n", num, prerequisites);

    if (res == ans) {
        fmt::print(fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fg(fmt::color::red), "Fail\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Got: {}\n", res);
    }
    cout << endl;
}

int main() {
    test(2, { {1,0} }, true);
    test(2, { {1,0},{0,1} }, false);
    test(3, { {1,0},{0,2},{2,1 } }, false);
    test(4, { {1,0},{2,0},{3,0} }, true);
    return 0;
}
