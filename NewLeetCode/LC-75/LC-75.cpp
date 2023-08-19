//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-75-Solution.h"
using namespace std;

int main() {
    int caseNum;
    vector<int> nums, ans, res;
    Solution sol;
    caseNum = 1;
    nums = { 2,0,2,1,1,0 };
    ans = { 0,0,1,1,2,2 };
    res = nums;
    sol.sortColors(res);
    fmt::print("case {}\n"
        "nums = {}\n"
        "ans = {}\n"
        "res = {}\n\n",
        caseNum, nums, ans, res);
    caseNum = 2;
    nums = { 1,1 };
    ans = { 1,1 };
    res = nums;
    sol.sortColors(res);
    fmt::print("case {}\n"
        "nums = {}\n"
        "ans = {}\n"
        "res = {}\n\n",
        caseNum, nums, ans, res);
    caseNum = 3;
    nums = { 1 };
    ans = { 1 };
    res = nums;
    sol.sortColors(res);
    fmt::print("case {}\n"
        "nums = {}\n"
        "ans = {}\n"
        "res = {}\n\n",
        caseNum, nums, ans, res);
    caseNum = 4;
    nums = { 2,2 };
    ans = { 2,2 };
    res = nums;
    sol.sortColors(res);
    fmt::print("case {}\n"
        "nums = {}\n"
        "ans = {}\n"
        "res = {}\n\n",
        caseNum, nums, ans, res);
    return 0;
}