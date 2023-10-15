#include "List.h"
#include "util.h"
#include <iostream>
#include "WEEK367-C.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    int i, v;
    vector<int> nums;
    vector<int> ans, res;

    fmt::print("Case {}\n", caseNum++);
    nums = { 2,7,0 };
    i = 0, v = 4;
    ans = { 0,1 };
    res = sol.findIndices(nums, i, v);
    fmt::print("nums: {}, i = {}, v = {}\n"
        "ans = {}\n"
        "res = {}\n", nums, i, v, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 5,1,4,1 };
    i = 2, v = 4;
    ans = { 0,3 };
    res = sol.findIndices(nums, i, v);
    fmt::print("nums: {}, i = {}, v = {}\n"
        "ans = {}\n"
        "res = {}\n", nums, i, v, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 2,1 };
    i = 0, v = 0;
    ans = { 0,0 };
    res = sol.findIndices(nums, i, v);
    fmt::print("nums: {}, i = {}, v = {}\n"
        "ans = {}\n"
        "res = {}\n", nums, i, v, ans, res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,2,3 };
    i = 2, v = 4;
    ans = { -1,-1 };
    res = sol.findIndices(nums, i, v);
    fmt::print("nums: {}, i = {}, v = {}\n"
        "ans = {}\n"
        "res = {}\n", nums, i, v, ans, res);

    return 0;
}
