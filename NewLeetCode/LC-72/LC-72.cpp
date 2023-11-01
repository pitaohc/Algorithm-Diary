#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-72.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    string word1, word2;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    word1 = "horse", word2 = "ros";
    ans = 3;
    fmt::print(
        "word1 = {}\n"
        "word2 = {}\n"
        "ans = {}, ",
        word1, word2, ans);
    res = sol.minDistance(word1, word2);
    fmt::print("res = {}\n", res);
    return 0;
}
