#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-71.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(string path, string ans) {
    Solution sol;
    static  int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("path: {}\n", path);
    auto res = sol.simplifyPath(path);
    if (res == ans) {
        fmt::print(fg(fmt::color::lime_green), "PASS\n");
    }
    else {
        fmt::print(fg(fmt::color::red), "FAIL!!!\n");
        fmt::print("EXPECTED: {}\n", ans);
        fmt::print("ACTUALLY: {}\n", res);

    }
}
int main() {
    test("/home/", "/home");
    test("/../", "/");
    test("/home//foo/", "/home/foo");
    test("/a/./b/../../c/", "/c");
    test("/a/../../b/../c//.//", "/c");

    return 0;
}
