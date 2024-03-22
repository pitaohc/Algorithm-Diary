#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-274.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<int> citations, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);

    fmt::print("citations: {}\n", citations);
    int res = sol.hIndex(citations);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::green), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actually: {}\n", res);
    }
}
int main() {

    test({ 3, 0, 6, 1, 5 }, 3);
    test({ 0,1,2,3,4,5,6,6,6,6 }, 5);
    //test({ 1,1 }, 1);
    return 0;
}
