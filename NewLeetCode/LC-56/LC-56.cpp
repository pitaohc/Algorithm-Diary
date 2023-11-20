#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-56.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> intervals, res, ans;

    fmt::print("Case {}\n", caseNum++);
    intervals = { {2,3,},{4,5,},{6,7,},{8,9,},{1,10}, };
    ans = { {1,10} };
    res = sol.merge(intervals);
    fmt::print("intervals = {}\n"
        "ans = {}\n"
        "res = {}\n", intervals, ans, res);

    fmt::print("Case {}\n", caseNum++);
    intervals = { {1,3},{2,6},{8,10} };
    ans = { {1,6},{8,10} };
    res = sol.merge(intervals);
    fmt::print("intervals = {}\n"
        "ans = {}\n"
        "res = {}\n", intervals, ans, res);

    fmt::print("Case {}\n", caseNum++);
    intervals = { {1,3},{3,6} };
    ans = { {1,6} };
    res = sol.merge(intervals);
    fmt::print("intervals = {}\n"
        "ans = {}\n"
        "res = {}\n", intervals, ans, res);

    fmt::print("Case {}\n", caseNum++);
    intervals = { {1,3} };
    ans = { {1,3} };
    res = sol.merge(intervals);
    fmt::print("intervals = {}\n"
        "ans = {}\n"
        "res = {}\n", intervals, ans, res);

    return 0;
}
