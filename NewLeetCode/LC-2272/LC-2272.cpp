#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-2272.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    string input,
    int ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: {}\n", input);


    auto res = sol.largestVariance(input);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }
    fmt::print("\n");

}
int main() {

    test("aababbb", 3);
    test("abcde", 0);

    return 0;
}
