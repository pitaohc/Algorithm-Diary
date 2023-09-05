#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-46.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    vector<vector<int>> ans, res;

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,2,3 };
    res = sol.permute(nums);
    fmt::print("nums: {}\n"
        "res:\n"
        "{}\n", nums, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,2,3,4 };
    res = sol.permute(nums);
    fmt::print("nums: {}\n"
        "res:\n"
        "{}\n", nums, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1 };
    res = sol.permute(nums);
    fmt::print("nums: {}\n"
        "res:\n"
        "{}\n", nums, res);
    

    return 0;
}
