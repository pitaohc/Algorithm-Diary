//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-215-Solution.h"
using namespace std;

int main() {
    vector<int> nums;
    int ans, res, caseNum, k;
    Solution sol;

    caseNum = 1;
    k = 2;
    nums = { 3,2,1,5,6,4 };
    ans = 5;
    res = sol.findKthLargest(nums, k);
    fmt::print("Case {}\n"
        "k = {}, nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, k, nums, ans, res);

    caseNum = 2;
    k = 4;
    nums = { 3,2,3,1,2,4,5,5,6 };
    ans = 4;
    res = sol.findKthLargest(nums, k);
    fmt::print("Case {}\n"
        "k = {}, nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, k, nums, ans, res);

    caseNum = 3;
    k = 2;
    nums = { 3,2,1,5,6,4 };
    ans = 5;
    res = sol.findKthLargest(nums, k);
    fmt::print("Case {}\n"
        "k = {}, nums = {}\n"
        "ans = {}, res = {}\n\n", caseNum, k, nums, ans, res);


    return 0;
}