#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-990.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<string> equations,bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("equations: \n{}\n", equations);
    bool res = sol.equationsPossible(equations);

    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actual: {}\n", res);
    }
}
int main() {
    test({ "a==b" }, true);
    test({ "a==b","a!=b"}, false);
    test({ "a==b","c!=a" }, true);
    return 0;
}
