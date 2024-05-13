#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-646.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    vector<vector<int>> pairs,
    int ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: {}\n", pairs);


    auto res = sol.findLongestChain(pairs);
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

    test({{1, 2}, {2, 3}, {3, 4}}, 2);
    test({ {1, 2}, {7,8}, {4,5} }, 3);
    test({ {1,2} }, 1);
    test({ {1,2},{1,2} }, 1);


    return 0;
}
