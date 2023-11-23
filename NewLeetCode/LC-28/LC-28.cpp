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
    s = "abcdabcea";
    p = "abcdabce";
    sol.strStr(s, p);

    return 0;
}
