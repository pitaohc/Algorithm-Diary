#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-14.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<string> strs;
    string ans, res;
    fmt::print("Case {}\n", caseNum++);
    strs = { "flower","flower","flower","flower" };
    ans = "flower";
    res = sol.longestCommonPrefix(strs);
    fmt::print("strs: {}\n"
        "ans = {}, res = {}\n", strs, ans, res);

    return 0;
}
