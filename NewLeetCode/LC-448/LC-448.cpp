#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-448.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums, res, ans;

    fmt::print("Case {}\n", caseNum++);
    nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
    fmt::print("nums = {}\n", nums);
    ans = { 5,6 };
    res = sol.findDisappearedNumbers(nums);
    fmt::print("ans = {}\n"
        "res = {}\n", ans, res);

    return 0;
}
