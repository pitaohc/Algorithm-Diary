#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-47.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    vector<vector<int>> res;

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,1,2 };
    res = sol.permuteUnique(nums);
    fmt::print("nums: {}\n"
        "results: \n", nums);
    for (auto& elem : res) {
        fmt::print("{}\n", elem);
    }

    fmt::print("Case {}\n", caseNum++);
    nums = { 0,0,0,1,9 };
    res = sol.permuteUnique(nums);
    fmt::print("nums: {}\n"
        "results: \n", nums);
    for (auto& elem : res) {
        fmt::print("{}\n", elem);
    }

    return 0;
}
