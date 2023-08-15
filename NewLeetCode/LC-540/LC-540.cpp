//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-540-Solution.h"
using namespace std;

int main() {
    vector<int> nums;
    int ans, res, caseNum;
    Solution sol;

    caseNum = 1;
    nums = { 1,1,2,3,3,4,4,8,8 };
    ans = 2;
    res = sol.singleNonDuplicate(nums);
    fmt::print("Case {}\n"
        "nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, nums, ans, res);

    caseNum = 2;
    nums = { 3,3,7,7,10,11,11 };
    ans = 10;
    res = sol.singleNonDuplicate(nums);
    fmt::print("Case {}\n"
        "nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, nums, ans, res);

    caseNum = 3;
    nums = { 3 };
    ans = 3;
    res = sol.singleNonDuplicate(nums);
    fmt::print("Case {}\n"
        "nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, nums, ans, res);

    caseNum = 4;
    nums = { 1,1,3 };
    ans = 3;
    res = sol.singleNonDuplicate(nums);
    fmt::print("Case {}\n"
        "nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, nums, ans, res);

    caseNum = 5;
    nums = { 1,3,3 };
    ans = 1;
    res = sol.singleNonDuplicate(nums);
    fmt::print("Case {}\n"
        "nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, nums, ans, res);

    return 0;
}