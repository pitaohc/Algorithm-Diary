#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-30.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
#include<algorithm>
using namespace std;
void test(string s, vector<string> words, vector<int> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("s: {}\n", s);
    fmt::print("words: {}\n", words);
    auto res = sol.findSubstring(s, words);
    sort(res.begin(), res.end());
    sort(ans.begin(), ans.end());
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::lime_green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actually: {}\n", res);
    }
}
int main() {


    test("abcdbad", { "a","b","d" }, { 3,4 });
    test("aaa", { "a","a" }, { 0,1 });
    test("aaa", { "a","a","a" }, { 0 });
    test("barfoothefoobarman", { "foo","bar" }, { 0,9 });
    test("wordgoodgoodgoodbestword", { "word","good","best","word" }, {});
    test("barfoofoobarthefoobarman", { "bar","foo","the" }, { 6,9,12 });


    return 0;
}
