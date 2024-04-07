#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-128.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<int> nums, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("Input: {}\n", nums);
    int res = sol.longestConsecutive(nums);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }
}
int main() {
    test({ 100,4,200,1,3,2 }, 4);
    test({ 0,3,7,2,5,8,4,6,0,1 }, 9);
    test({}, 0);
    test({ 1 }, 1);

    return 0;
}
