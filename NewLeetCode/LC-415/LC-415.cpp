#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-415.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string num1, num2, res, ans;

    fmt::print("Case {}\n", caseNum++);
    num1 = "11";
    num2 = "123";
    ans = "134";
    fmt::print("{} + {} = {}, ", num1, num2, ans);
    res = sol.addStrings(num1, num2);
    fmt::print("{}\n", res);

    fmt::print("Case {}\n", caseNum++);
    num1 = "0";
    num2 = "123";
    ans = "123";
    fmt::print("{} + {} = {}, ", num1, num2, ans);
    res = sol.addStrings(num1, num2);
    fmt::print("{}\n", res);

    fmt::print("Case {}\n", caseNum++);
    num1 = "0";
    num2 = "0";
    ans = "0";
    fmt::print("{} + {} = {}, ", num1, num2, ans);
    res = sol.addStrings(num1, num2);
    fmt::print("{}\n", res);

    fmt::print("Case {}\n", caseNum++);
    num1 = "123";
    num2 = "0";
    ans = "123";
    fmt::print("{} + {} = {}, ", num1, num2, ans);
    res = sol.addStrings(num1, num2);
    fmt::print("{}\n", res);

    fmt::print("Case {}\n", caseNum++);
    num1 = "555";
    num2 = "555";
    ans = "1110";
    fmt::print("{} + {} = {}, ", num1, num2, ans);
    res = sol.addStrings(num1, num2);
    fmt::print("{}\n", res);

    fmt::print("Case {}\n", caseNum++);
    num1 = "5555";
    num2 = "555";
    ans = "6110";
    fmt::print("{} + {} = {}, ", num1, num2, ans);
    res = sol.addStrings(num1, num2);
    fmt::print("{}\n", res);

    return 0;
}
