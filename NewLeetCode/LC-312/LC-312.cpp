#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-312.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    int res, ans;

    fmt::print("Case {}\n", caseNum++);
    nums = { 3,1,5,8 };
    ans = 167;
    fmt::print(
        "nums = {}\n"
        "ans = {}, ", 
        nums, ans);
    res = sol.maxCoins(nums);
    fmt::print("res = {}\n", res);
    return 0;
}
