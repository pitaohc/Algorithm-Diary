#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-560.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    int k, res, ans;

    fmt::print("Case {}\n", caseNum++);
    nums = { -1,-1,1 };
    k = 0;
    ans = 1;
    fmt::print("nums: {}\n"
        "k = {}\n"
        "ans = {}, ", nums, k, ans);
    res = sol.subarraySum(nums, k);
    fmt::print("res = {}\n", res);

    return 0;
}
