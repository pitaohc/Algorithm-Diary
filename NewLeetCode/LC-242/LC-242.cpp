#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-242.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string s, t;
    bool res, ans;

    fmt::print("Case {}\n", caseNum++);
    s = "anagram";
    t = "nagaram";
    ans = true;
    fmt::print("s = {}, t = {}\n"
        "ans = {}\n", s, t, ans);
    res = sol.isAnagram(s, t);
    fmt::print("res = {}\n", res);
    return 0;
}
