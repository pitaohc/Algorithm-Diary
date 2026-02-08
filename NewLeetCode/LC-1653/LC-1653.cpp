#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1653.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    std::string s,
    int ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("S: {}\n", s);


    auto res = sol.minimumDeletions(s);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }


}
int main() {
    test("aababbab",2);
    test("aaaaaa",0);
    test("bbbbbb",0);
    test("a",0);
    test("b",0);
    test("ab",0);
    test("ba",1);
    test("aba",1);
    test("abba",1);
    test("abbaa",2);


    return 0;
}
