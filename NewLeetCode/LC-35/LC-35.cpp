#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-35.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    int ans, res,target;

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,3,5,6 };
    target = 2;
    ans = 1;
    res = sol.searchInsert(nums, target);
    fmt::print("nums = {}, target = {}\n"
        "ans = {}, res = {}\n",
        nums, target, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,3,5,6 };
    target = 7;
    ans = 4;
    res = sol.searchInsert(nums, target);
    fmt::print("nums = {}, target = {}\n"
        "ans = {}, res = {}\n",
        nums, target, ans, res);

    return 0;
}
