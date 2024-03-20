#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-97.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(string s1, string s2, string s3, bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    bool res = sol.isInterleave(s1, s2, s3);
    fmt::print("Input: \ns1: {}\ns2: {}\ns3: {}\n", s1, s2, s3);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS!\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL!\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actually: {}\n", res);
    }
}
int main() {

    test("aabcc", "dbbca", "aadbbcbcac", true);
    return 0;
}
