#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-120.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

void test(vector<vector<int>> triangle, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("triangle:\n");
    for (const auto& layer : triangle) {
        fmt::print("{}\n", layer);
    }
    int res = sol.minimumTotal(triangle);
    fmt::print("ans = {}, res = {}\n", ans, res);
}
int main() {
    test({ {1} }, 1);

    test({ {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} }, 11);


    return 0;
}
