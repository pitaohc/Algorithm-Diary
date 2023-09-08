#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-79.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<char>>board;
    string word;
    bool ans, res;

    board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    word = "ABCCED";
    ans = true;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("board:\n"
        "{}\n"
        "word: {}\n"
        "ans = {}, \n",
        board, word, ans);
    res = sol.exist(board, word);
    fmt::print("res = {}\n", res);

    board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    word = "SEE";
    ans = true;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("board:\n"
        "{}\n"
        "word: {}\n"
        "ans = {}, \n",
        board, word, ans);
    res = sol.exist(board, word);
    fmt::print("res = {}\n", res);

    board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    word = "ABCB";
    ans = false;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("board:\n"
        "{}\n"
        "word: {}\n"
        "ans = {}, \n",
        board, word, ans);
    res = sol.exist(board, word);
    fmt::print("res = {}\n", res);


    return 0;
}
