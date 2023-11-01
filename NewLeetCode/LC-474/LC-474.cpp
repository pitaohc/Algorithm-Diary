#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-474.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;

    vector<string> strs;
    int m, n;
    int ans, res;
    fmt::print("Case {}\n", caseNum++);
    strs = { "10", "0001", "111001", "1", "0" };
    m = 5, n = 3;
    ans = 4;
    fmt::print(
        "strs: {}\n"
        "m = {}, n = {}\n"
        "ans = {}, ",
        strs, m, n, ans);
    res = sol.findMaxForm(strs, m, n);
    fmt::print("res = {}\n", res);
    return 0;
}
