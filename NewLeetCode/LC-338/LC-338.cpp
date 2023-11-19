#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-338.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    int n;
    vector<int> res, ans;

    fmt::print("Case {}\n", caseNum++);
    n = 5;
    ans = { 0,1,1,2,1,2 };
    res = sol.countBits(n);
    fmt::print("n = {}\n"
        "ans = {}\n"
        "res = {}\n", n, ans, res);
    return 0;
}
