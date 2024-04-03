#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-6.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(string s,int numrows,string ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("s: {}\n"
        "numRows: {}\n", s, numrows);
    string res = sol.convert(s, numrows);
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
    test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    test("A", 1, "A");
    return 0;
}
