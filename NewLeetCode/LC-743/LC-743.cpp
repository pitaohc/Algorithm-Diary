#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-743.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<vector<int>> times, int n, int k, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: times = {}, n = {}, k = {}\n", times, n, k);
    int res = sol.networkDelayTime(times, n, k);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Got: {}\n", res);
    }
}
int main() {

    test({ {2, 1, 1}, {2, 3, 1}, {3, 4, 1} }, 4, 2, 2);
    test({ {1,2,1} }, 2, 1, 1);
    test({ {1,2,1} }, 2, 2, -1);
    return 0;
}
