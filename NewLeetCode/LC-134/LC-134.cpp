#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-134.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<int> gas, vector<int> cost, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print(
        "gas : {}\n"
        "cost: {}\n",
        gas, cost);
    auto res = sol.canCompleteCircuit(gas, cost);
    if (res == ans) {
        fmt::print(fg(fmt::color::lime_green), "PASS\n");
    }
    else {
        fmt::print(fg(fmt::color::red), "FAIL!!!\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Returned: {}\n", res);
    }
}
int main() {
    test({ 3,3,4 }, { 3,4,4 }, -1);
    test({ 1, 2, 3, 4, 5 }, { 3, 4, 5, 1, 2 }, 3);
    test({ 2, 3, 4 }, { 3, 4, 3 }, -1);
    test({ 4 }, { 5 }, -1);
    return 0;
}
