#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1042.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(int n, vector<vector<int>> paths,vector<int> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    auto res = sol.gardenNoAdj(n, paths);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Got: {}\n", res);
    }
    
}
int main() {


    test(3, { {1,2},{2,3},{3,1} }, { 1,2,3 });
    test(4, { {1,2},{3,4} }, { 1,2,1,2 });
    test(4, { {1,2},{2,3},{3,4},{4,1},{1,3},{2,4} }, { 1,2,3,4 });
    return 0;
}
