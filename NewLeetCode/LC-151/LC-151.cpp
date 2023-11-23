#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-151.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string s, res, ans;

    fmt::print("Case {}\n", caseNum++);
    s = "the sky is blue";
    ans = "blue is sky the";
    fmt::print(
        "  s = {}\n"
        "ans = {}\n", s, ans);
    res = sol.reverseWords(s);
    fmt::print(
        "res = {}\n", res);

    fmt::print("Case {}\n", caseNum++);
    s = "  hello world  ";
    ans = "world hello";
    fmt::print(
        "  s = {}\n"
        "ans = {}\n", s, ans);
    res = sol.reverseWords(s);
    res = sol.reverseWords(s);
    fmt::print(
        "res = {}\n", res);

    return 0;
}
