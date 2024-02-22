#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-96.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(int n, int ans) {
    Solution sol;
    int caseNum = 1;

    fmt::print("Case {}\n", caseNum++);
    fmt::print("n = {}\n", n);
    int res = sol.numTrees(n);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actually: {}\n", res);
    }
}
int main() {

    test(1, 1);
    test(3, 5);

    return 0;
}
