//
// Created by devcpp on 23-8-14.
//
#include"LC-154-Solution.h"
#include "stdc++.h"
#include <cmath>
#include<fmt/core.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    fmt::print(
        "154. 寻找旋转排序数组中的最小值 II\n"
        "https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/\n");
    Solution sol;
    vector<int> nums;
    int ans, res, caseNum;

    caseNum = 1;
    nums = { 1,3,5 };
    ans = 1;
    res = sol.findMin(nums);
    fmt::print(
        "Case {}\n"
        "nums = {}\n"
        "res = {}\n"
        "ans = {}\n"
        "\n", caseNum, fmt::join(nums, ", "), res, ans
    );

    caseNum = 2;
    nums = { 2,2,2,0,1 };
    ans = 0;
    res = sol.findMin(nums);
    fmt::print(
        "Case {}\n"
        "nums = {}\n"
        "res = {}\n"
        "ans = {}\n"
        "\n", caseNum, fmt::join(nums, ", "), res, ans
    );

    caseNum = 3;
    nums = { 1 };
    ans = 1;
    res = sol.findMin(nums);
    fmt::print(
        "Case {}\n"
        "nums = {}\n"
        "res = {}\n"
        "ans = {}\n"
        "\n", caseNum, fmt::join(nums, ", "), res, ans
    );

    caseNum = 4;
    nums = { 1,2,3,4 };
    ans = 1;
    res = sol.findMin(nums);
    fmt::print(
        "Case {}\n"
        "nums = {}\n"
        "res = {}\n"
        "ans = {}\n"
        "\n", caseNum, fmt::join(nums, ", "), res, ans
    );

    caseNum = 5;
    nums = { 2,2,2,2 };
    ans = 2;
    res = sol.findMin(nums);
    fmt::print(
        "Case {}\n"
        "nums = {}\n"
        "res = {}\n"
        "ans = {}\n"
        "\n", caseNum, fmt::join(nums, ", "), res, ans
    );

    caseNum = 6;
    nums = { 3,3,1,3 };
    ans = 1;
    res = sol.findMin(nums);
    fmt::print(
        "Case {}\n"
        "nums = {}\n"
        "res = {}\n"
        "ans = {}\n"
        "\n", caseNum, fmt::join(nums, ", "), res, ans
    );


    return 0;
}