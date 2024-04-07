#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-392.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(string s, string t, bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("s: {}\n", s);
    fmt::print("t: {}\n", t);
    bool res = sol.isSubsequence(s, t);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Returned: {}\n", res);
    }
}
int main() {
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    test("", "abc", true);
    test("", "", true);

    return 0;
}
