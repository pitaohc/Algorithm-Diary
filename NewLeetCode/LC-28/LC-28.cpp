#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-28.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;

    string s, p;
    fmt::print("Case {}\n", caseNum++);
    p = "abcdabce";
    fmt::print("p = {}\n"
        "n = {}\n", p, sol.buildNext(p));

    return 0;
}
