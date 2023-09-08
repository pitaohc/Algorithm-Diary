#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-77.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    int n, k;
    vector<vector<int>> res, ans;

    fmt::print("Case {}\n", caseNum++);
    n = 4, k = 2;
    res = sol.combine(n, k);
    fmt::print("n = {}, k = {}\n"
        "res = \n"
        "{}\n\n",
        n, k, res);

    fmt::print("Case {}\n", caseNum++);
    n = 1, k = 1;
    res = sol.combine(n, k);
    fmt::print("n = {}, k = {}\n"
        "res = \n"
        "{}\n\n",
        n, k, res);

    fmt::print("Case {}\n", caseNum++);
    n = 2, k = 2;
    res = sol.combine(n, k);
    fmt::print("n = {}, k = {}\n"
        "res = \n"
        "{}\n\n",
        n, k, res);


    return 0;
}
