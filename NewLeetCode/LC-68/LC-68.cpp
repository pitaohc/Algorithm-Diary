#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-68.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<string> words, int maxWidth, vector<string> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("words: {}\n", words);
    fmt::print("maxWidth: {}\n", maxWidth);
    auto res = sol.fullJustify(words, maxWidth);
    if(res == ans) {
        fmt::print(fg(fmt::color::lime_green), "Passed\n");
    } else {
        fmt::print(fg(fmt::color::red), "Failed\n");
        fmt::print("Expected: \n");
        for (const auto& line : ans) {
            cout<<"\"" << line << "\"" << endl;
        }
        fmt::print("Returned: \n");
        for (const auto& line : res) {
            cout << "\"" << line << "\"" << endl;
        }
    }
}
int main() {
    test({ "ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"}, 16, 
        {
        });
    test({ "This", "is", "an", "example", "of", "text", "justification." },16,
         { 
            "This    is    an", 
            "example  of text", 
            "justification.  " });
    test({ "What","must","be","acknowledgment","shall","be" }, 16, 
        {
          "What   must   be",
          "acknowledgment  ",
          "shall be        " });
    test({ "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" }, 20, 
        {
          "Science  is  what we",
          "understand      well",
          "enough to explain to",
          "a  computer.  Art is",
          "everything  else  we",
          "do                  "
        });

    return 0;
}
