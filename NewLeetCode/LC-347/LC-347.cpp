//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-347-Solution.h"
using namespace std;

int main() {
    vector<int> nums, ans, res;
    int k, caseNum;
    Solution sol;

    caseNum = 1;
    k = 2;
    nums = { 1,1,1,2,2,3 };
    ans = { 1,2 };
    res = sol.topKFrequent(nums, k);
    fmt::print("case {}\n"
        "nums = {}, k = {}\n"
        "ans = {}, res = {}\n",
        caseNum,
        nums, k,
        ans, res);
    return 0;
}