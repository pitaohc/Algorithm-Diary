#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-932.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    int n;
    vector<int> ans;
    vector<int> res;

    fmt::print("Case {}\n", caseNum++);
    n = 5;
    fmt::print("n = {}\n", n);
    res = sol.beautifulArray(n);
    fmt::print("res = {}\n", res);


    return 0;
}
