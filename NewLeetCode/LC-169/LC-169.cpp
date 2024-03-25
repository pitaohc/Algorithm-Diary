#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-169.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<int> nums, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("nums: {}\n", nums);
    int res = sol.majorityElement(nums);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS!\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL!\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actually: {}\n", res);
    }
}
int main() {
    test({ 2,1,3,3,3,5,6 }, 3);
    test({ 1,2,2,2,1,1,2, }, 2);


    return 0;
}
