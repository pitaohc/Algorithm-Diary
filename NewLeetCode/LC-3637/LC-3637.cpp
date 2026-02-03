#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-3637.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    vector<int> nums,
    bool ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("nums: {}\n", nums);


    auto res = sol.isTrionic(nums);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }


}
int main() {
    test({3,2,1},false);
    test({1,2,3},false);
    test({1,1,1},false);
    test({1,3,2},false);
    test({2,1,3},false);
    test({1,3,5,4,2,6},true);
    return 0;
}
