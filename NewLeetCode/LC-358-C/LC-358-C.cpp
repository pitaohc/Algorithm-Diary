//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-358-C-Solution.h"
#include<map>
using namespace std;

int main() {
    Solution sol;
    vector<int> nums;
    int x, ans, res, caseNum;

    //map<int, int>m;
    //m[5] = 5;
    //m[10] = 10;
    //m[15] = 15;




    caseNum = 1;
    nums = { 4,3,2,4 };
    x = 2;
    ans = 0;
    res = sol.minAbsoluteDifference(nums, x);
    fmt::print("case {}\n"
        "nums = {}, k = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        nums, x,
        ans, res);
    cout << flush;
    caseNum = 2;
    nums = { 5,3,2,10,15 };
    x = 1;
    ans = 1;
    res = sol.minAbsoluteDifference(nums, x);
    fmt::print("case {}\n"
        "nums = {}, k = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        nums, x,
        ans, res);
    cout << flush;

    caseNum = 3;
    nums = { 1,2,3,4 };
    x = 3;
    ans = 3;
    res = sol.minAbsoluteDifference(nums, x);
    fmt::print("case {}\n"
        "nums = {}, k = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        nums, x,
        ans, res);
    cout << flush;

    caseNum = 4;
    nums = { 9,113,136 };
    x = 1;
    ans = 23;
    res = sol.minAbsoluteDifference(nums, x);
    fmt::print("case {}\n"
        "nums = {}, k = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        nums, x,
        ans, res);
    cout << flush;

    caseNum = 5;
    nums = { 10,109,391,356,280,311 };
    x = 3;
    ans = 80;
    res = sol.minAbsoluteDifference(nums, x);
    fmt::print("case {}\n"
        "nums = {}, k = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        nums, x,
        ans, res);
    cout << flush;


}