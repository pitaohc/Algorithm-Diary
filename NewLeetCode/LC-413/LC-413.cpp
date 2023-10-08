#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-413.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,2,3,4 };
    ans = 3;
    res = sol.numberOfArithmeticSlices(nums);
    fmt::print(
        "nums: {}\n"
        "ans = {}, res = {}\n",
        nums, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,2,3,4,5 };
    ans = 6;
    res = sol.numberOfArithmeticSlices(nums);
    fmt::print(
        "nums: {}\n"
        "ans = {}, res = {}\n",
        nums, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1 };
    ans = 0;
    res = sol.numberOfArithmeticSlices(nums);
    fmt::print(
        "nums: {}\n"
        "ans = {}, res = {}\n",
        nums, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,2,3,7,8,9 };
    ans = 2;
    res = sol.numberOfArithmeticSlices(nums);
    fmt::print(
        "nums: {}\n"
        "ans = {}, res = {}\n",
        nums, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,3,4,5 };
    ans = 1;
    res = sol.numberOfArithmeticSlices(nums);
    fmt::print(
        "nums: {}\n"
        "ans = {}, res = {}\n",
        nums, ans, res);

    return 0;
}
