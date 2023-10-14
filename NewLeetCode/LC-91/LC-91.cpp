#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-91.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;

    string s;
    int ans, res;
    fmt::print("Case {}\n", caseNum++);
    s = "12";
    ans = 2;
    res = sol.numDecodings(s);
    fmt::print(
        "s = {}\n"
        "ans = {}, res = {}\n", s, ans, res);

    fmt::print("Case {}\n", caseNum++);
    s = "27";
    ans = 1;
    res = sol.numDecodings(s);
    fmt::print(
        "s = {}\n"
        "ans = {}, res = {}\n", s, ans, res);

    fmt::print("Case {}\n", caseNum++);
    s = "0027";
    ans = 0;
    res = sol.numDecodings(s);
    fmt::print(
        "s = {}\n"
        "ans = {}, res = {}\n", s, ans, res);

    fmt::print("Case {}\n", caseNum++);
    s = "6";
    ans = 1;
    res = sol.numDecodings(s);
    fmt::print(
        "s = {}\n"
        "ans = {}, res = {}\n", s, ans, res);

    fmt::print("Case {}\n", caseNum++);
    s = "123";
    ans = 3;
    res = sol.numDecodings(s);
    fmt::print(
        "s = {}\n"
        "ans = {}, res = {}\n", s, ans, res);

    return 0;
}
