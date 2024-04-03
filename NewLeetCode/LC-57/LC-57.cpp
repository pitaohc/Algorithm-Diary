#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-57.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<vector<int>> intervals, vector<int> newInterval, vector<vector<int>> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("intervals: {}\n", intervals);
    fmt::print("newInterval: {}\n", newInterval);
    auto res = sol.insert(intervals, newInterval);

    if (res == ans) {
        fmt::print(fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fg(fmt::color::red), "FAIL\n");
        fmt::print("res: {}\n", res);
        fmt::print("ans: {}\n", ans);
    }
}
int main() {
    test({ {0,1},{3,5} }, { -2,-1 }, { {-2,-1},{0,1},{3,5} }); // 区间前端
    test({ {0,1},{3,5} }, { 6,8 }, { {0,1},{3,5},{6,8}, }); //区间尾端
    test({ {1, 3}, {6, 9} }, { 2, 5 }, { {1, 5}, {6, 9} });
    test({ {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16} }, { 4, 8 }, { {1, 2}, {3, 10}, {12, 16} });

    return 0;
}
