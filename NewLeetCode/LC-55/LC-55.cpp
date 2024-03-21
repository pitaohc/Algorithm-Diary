#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-55.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<int> nums, bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("nums: {}\n", nums);
    bool res = sol.canJump(nums);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL!!!\n");
        fmt::print("Excepted: {}\n", ans);
        fmt::print("Actually: {}\n", res);
    }
}
int main() {

    test({ 1,1,0,1 }, false);
    test({ 2,3,1,1,4 }, true);
    test({ 3,2,1,0,4 }, false);
    test({ 0 }, true);
    test({ 2,0 }, true);

    return 0;
}
