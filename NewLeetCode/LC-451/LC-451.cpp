//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-451-Solution.h"
using namespace std;

int main() {
    Solution sol;
    string s, res, ans;
    int caseNum;

    caseNum = 1;
    s = "tree";
    ans = "eert";
    res = sol.frequencySort(s);
    fmt::print("case {}\n"
        "s = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        s,
        ans, res);

    caseNum = 2;
    s = "cccaaa";
    ans = "cccaaa";
    res = sol.frequencySort(s);
    fmt::print("case {}\n"
        "s = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        s,
        ans, res);

    caseNum = 3;
    s = "Aabb";
    ans = "bbAa";
    res = sol.frequencySort(s);
    fmt::print("case {}\n"
        "s = {}\n"
        "ans = {}, res = {}\n\n",
        caseNum,
        s,
        ans, res);

    return 0;
}