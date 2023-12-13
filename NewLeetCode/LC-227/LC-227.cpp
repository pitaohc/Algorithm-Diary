#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-227.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string s;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    s = "2147483647";
    ans = 2147483647;
    fmt::print(" s:{}\n"
        " ans = {}, ", s, ans);
    res = sol.calculate(s);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    s = " 3+5 / 2 ";
    ans = 5;
    fmt::print(" s:{}\n"
        " ans = {}, ", s, ans);
    res = sol.calculate(s);
    fmt::print("res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    s = " 3+2 *2";
    ans = 7;
    fmt::print(" s:{}\n"
        " ans = {}, ", s, ans);
    res = sol.calculate(s);
    fmt::print("res = {}\n", res);
    return 0;
}
