#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-209.h"
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
    nums = { 2, 3, 1, 2, 4, 3 };
    target = 7;
    ans = 2;
    res = sol.minSubArrayLen(target, nums);
    fmt::print("nums = {}, target = {}\n"
        "ans = {}, res = {}\n", nums, target, ans, res);
    return 0;
}
