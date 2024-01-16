#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-841.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<vector<int>> rooms, bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("rooms: {}\n", rooms);
    bool res = sol.canVisitAllRooms(rooms);
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
    test({ {0,1},{} }, true);
    test({ {1},{2},{3},{} }, true);
    test({ {1,3},{3,0,1},{2},{0} }, false);
    test({ {1},{2},{3},{0} }, true);
    test({ {1},{2},{3},{0},{} }, false);
    test({ {},{1} }, false);
    test({ {},{1},{1} }, false);
    return 0;
}
