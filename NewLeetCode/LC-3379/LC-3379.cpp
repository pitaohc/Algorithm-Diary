#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-3379.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    vector<int> nums,
    vector<int> ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    //fmt::print("Input: {}\n", input);


    auto res = sol.constructTransformedArray(nums);
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
    test({3,-2,1,1},{1,1,1,3});


    return 0;
}
