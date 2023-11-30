#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-239.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums, ans, res;
    int k;

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,3,1,2,0,5 };
    k = 3;
    ans = { 3,3,2,5 };
    fmt::print("nums = {}, k = {}\n"
        "ans = {}\n", nums, k, ans);
    res = sol.maxSlidingWindow(nums, k);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 7,2,4 };
    k = 2;
    ans = { 7,4 };
    fmt::print("nums = {}, k = {}\n"
        "ans = {}\n", nums, k, ans);
    res = sol.maxSlidingWindow(nums, k);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 7,2,4 };
    k = 1;
    ans = { 7,2,4 };
    fmt::print("nums = {}, k = {}\n"
        "ans = {}\n", nums, k, ans);
    res = sol.maxSlidingWindow(nums, k);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    nums = { 1,3,-1,-3,5,3,6,7 };
    k = 3;
    ans = { 3,3,5,5,6,7 };
    fmt::print("nums = {}, k = {}\n"
        "ans = {}\n", nums, k, ans);
    res = sol.maxSlidingWindow(nums, k);
    fmt::print("res = {}\n", res);

    return 0;
}
