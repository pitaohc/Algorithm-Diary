#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1192.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(int n, vector<vector<int>> connections, vector<vector<int>> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);

    auto res = sol.criticalConnections(n, connections);

    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actual: {}\n", res);
    }
}
int main() {

    test(4, { {0,1},{1,2},{2,0},{1,3} }, { {1,3} });
    test(5, { {1,0},{2,0},{3,2},{4,2},{4,3},{3,0},{4,0} }, { {0,1} });

    return 0;
}
