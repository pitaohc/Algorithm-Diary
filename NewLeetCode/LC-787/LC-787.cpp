#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-787.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;


void test(int n, vector<vector<int>> flights, int src, int dst, int k, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: n = {}, flights = {}, src = {}, dst = {}, k = {}\n", n, flights, src, dst, k);
    int res = sol.findCheapestPrice(n, flights, src, dst, k);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
        fmt::print("Output: {}\n", res);
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "ERROR\n");
        fmt::print("Output: {}\n", res);
        fmt::print("Expected: {}\n", ans);
    }
}
int main() {
    test(4, { {0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1} }, 0, 3, 1, 6);
    test(3, { {0, 1, 100}, {1, 2, 100}, {0, 2, 500} }, 0, 2, 1, 200);
    test(3, { {0, 1, 100}, {1, 2, 100}, {0, 2, 500} }, 0, 2, 0, 500);
    test(4, { {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200} }, 0, 3, 1, 700);
    test(5, { {4, 1, 1}, {1, 2, 3}, {0, 3, 2}, {0, 4, 10}, {3, 1, 1}, {1, 4, 3} }, 2, 1, 1, -1);
    return 0;
}
