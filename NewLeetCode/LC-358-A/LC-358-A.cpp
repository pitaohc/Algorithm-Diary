//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-358-A-Solution.h"
using namespace std;

int main() {
    Solution sol;
    vector<int> nums;
    int ans, res, caseNum;

    caseNum = 1;
    nums = { 51,71,17,24,42 };
    ans = 88;
    res = sol.maxSum(nums);
    fmt::print("case {}\n"
        "nums = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum, nums, ans, res);

    caseNum = 2;
    nums = { 1,2,3,4 };
    ans = -1;
    res = sol.maxSum(nums);
    fmt::print("case {}\n"
        "nums = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum, nums, ans, res);
    return 0;
}