#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-438.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;
void test(string s, string p, vector<int> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: s = {}, p = {}\n", s, p);
    auto res = sol.findAnagrams(s, p);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL!!!\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Returned: {}\n", res);
    }
}
int main() {

    test("cbaebabacd", "abc", { 0, 6 });
    test("abab", "ab", { 0, 1, 2 });
    test("aaaaa", "a", { 0,1,2,3,4 });

    return 0;
}
