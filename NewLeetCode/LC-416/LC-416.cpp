#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-416.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    bool res, ans;

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,5,10,6 };
    ans = true;
    fmt::print("nums = {}\n", nums);
    res = sol.canPartition(nums);
    fmt::print("ans = {}, res = {}\n", ans, res);

    return 0;
}
