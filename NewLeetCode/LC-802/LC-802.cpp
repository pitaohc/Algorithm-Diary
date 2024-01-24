#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-802.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<vector<int>> graph,vector<int> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);

    fmt::print("Input: {}\n", graph);
    auto res = sol.eventualSafeNodes(graph);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Output: {}\n", res);
        fmt::print("Expected: {}\n", ans);
    }

    cout << endl;
}
int main() {
    test({{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}} , {2,4,5,6});


    return 0;
}
