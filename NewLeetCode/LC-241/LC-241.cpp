#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-241.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string expression;
    vector<int> res;
    fmt::print("Case {}\n", caseNum++);
    expression = "2*3-4*5";
    fmt::print("expression: {}\n", expression);
    res = sol.diffWaysToCompute(expression);

    return 0;
}
