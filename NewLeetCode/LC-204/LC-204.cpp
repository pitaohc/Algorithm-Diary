#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-204.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    int n, ans, res;

    fmt::print("Case {}\n", caseNum++);
    n = 2;
    ans = 0;
    res = sol.countPrimes(n);
    fmt::print("n = {}, ans = {}, res = {}\n", n, ans, res);

    fmt::print("Case {}\n", caseNum++);
    n = 3;
    ans = 1;
    res = sol.countPrimes(n);
    fmt::print("n = {}, ans = {}, res = {}\n", n, ans, res);

    fmt::print("Case {}\n", caseNum++);
    n = 4;
    ans = 1;
    res = sol.countPrimes(n);
    fmt::print("n = {}, ans = {}, res = {}\n", n, ans, res);

    fmt::print("Case {}\n", caseNum++);
    n = 7;
    ans = 3;
    res = sol.countPrimes(n);
    fmt::print("n = {}, ans = {}, res = {}\n", n, ans, res);

    fmt::print("Case {}\n", caseNum++);
    n = 10;
    ans = 4;
    res = sol.countPrimes(n);
    fmt::print("n = {}, ans = {}, res = {}\n", n, ans, res);

    return 0;
}