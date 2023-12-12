#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-28.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string haystack, needle;
    int res, ans;

    fmt::print("Case {}\n", caseNum++);
    haystack = "mississippi";
    needle = "issip";
    ans = 4;
    fmt::print("h = {}, n = {}\n"
        "ans = {}\n", haystack, needle, ans);
    res = sol.strStr(haystack, needle);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    haystack = "aaa";
    needle = "aaa";
    ans = 0;
    fmt::print("h = {}, n = {}\n"
        "ans = {}\n", haystack, needle, ans);
    res = sol.strStr(haystack, needle);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    haystack = "hello";
    needle = "ll";
    ans = 2;
    fmt::print("h = {}, n = {}\n"
        "ans = {}\n", haystack, needle, ans);
    res = sol.strStr(haystack, needle);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    haystack = "sadbutsad";
    needle = "sad";
    ans = 0;
    fmt::print("h = {}, n = {}\n"
        "ans = {}\n", haystack, needle, ans);
    res = sol.strStr(haystack, needle);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    haystack = "leetcode";
    needle = "leeto";
    ans = -1;
    fmt::print("h = {}, n = {}\n"
        "ans = {}\n", haystack, needle, ans);
    res = sol.strStr(haystack, needle);
    fmt::print("res = {}\n", res);

    return 0;
}
