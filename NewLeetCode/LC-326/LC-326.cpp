#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-326.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    system("chcp 65001");

    Solution sol;
    int caseNum = 1;
    int num;
    bool ans, res;

    fmt::print("Case {}\n", caseNum++);
    num = 27;
    ans = true;
    fmt::print("num = {}\n"
        "ans = {}, ", num, ans);
    res = sol.isPowerOfThree(num);
    fmt::print("res = {}\n", res);
    return 0;
}
