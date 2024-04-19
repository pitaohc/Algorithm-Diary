#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1883.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    vector<int> dist, int speed, int hoursBefore, int ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    //fmt::print("Input: {}\n", input);
    fmt::print("dist: \n"
        "{}\n"
        "speed: {}, hoursBefore: {}\n", dist, speed, hoursBefore);

    auto res = sol.minSkips(dist, speed, hoursBefore);
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
    test({ 1,3,2 }, 4, 2, 1);
    test({ 7,3,5,5 }, 2, 10, 2);
    test({ 7,3,5,5 }, 1, 10, -1);

    return 0;
}
