#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1963.h"
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


    auto res = sol.minSwaps(input);
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

    test("][][", 1);
    test("]]][[[", 2);
    test("[]", 0);
    test("][", 1);
    test("][][][", 1);
    test("]][[[]", 1);

    return 0;
}
