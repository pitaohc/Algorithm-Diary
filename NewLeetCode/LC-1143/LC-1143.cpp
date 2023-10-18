#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-1143.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string text1, text2;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    text1 = "abc";
    text2 = "ebcd";
    ans = 2;
    fmt::print("text1 = {}\n"
        "text2 = {}\n"
        "ans = {}, ", text1, text2, ans);
    res = sol.longestCommonSubsequence(text1, text2);
    fmt::print("res = {}\n", res);
    return 0;
}
