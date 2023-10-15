#include "List.h"
#include "util.h"
#include <iostream>
#include "WEEK367-B.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string s, ans, res;
    int k;
    fmt::print("Case {}\n", caseNum++);
    s = "01011101000111110";
    k = 5;
    ans = "11111";
    res = sol.shortestBeautifulSubstring(s, k);
    fmt::print(
        "s = {}, k = {}\n"
        "ans = {}\n"
        "res = {}\n", s, k, ans, res);

    fmt::print("Case {}\n", caseNum++);
    s = "100011001";
    k = 3;
    ans = "11001";
    res = sol.shortestBeautifulSubstring(s, k);
    fmt::print(
        "s = {}, k = {}\n"
        "ans = {}\n"
        "res = {}\n", s, k, ans, res);

    return 0;
}
