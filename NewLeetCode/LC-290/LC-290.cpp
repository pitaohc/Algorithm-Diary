#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-290.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    string pattern, string s,bool ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("pattern: {}\n", pattern);
    fmt::print("s: {}\n", s);


    auto res = sol.wordPattern(pattern,s);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }


}
int main() {
    test("aaaa", "b a a b", false);
    test("abc", "dog cat dog", false);
    test("a", "dog dog", false);
    test("a", "dog", true);
    test("abba", "dog cat cat dog", true);
    test("abba", "dog cat cat fish", false);
    test("aaaa", "dog cat cat dog", false);


    return 0;
}
