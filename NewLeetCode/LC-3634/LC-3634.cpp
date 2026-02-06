#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-3634.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(
    vector<int> nums,
    int k,
    int ans
)
{
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("nums: {}\n", nums);
    fmt::print("k: {}\n", k);


    auto res = sol.minRemoval(nums,k);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }
}

int main()
{
    test({100000,100001,100002}, 1000000, 0);
    test({2,1,5}, 2, 1);
    test({1,6,2,9}, 3, 2);
    test({4,6}, 2, 0);
    test({1},10,0);
    test({10,1},10,0);
    return 0;
}
