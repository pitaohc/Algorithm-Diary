#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-289.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<vector<int>> board,vector<vector<int>> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("board:\n");
    for (const auto& t : board) {
        fmt::print("{}\n", t);
    }
    sol.gameOfLife(board);
    if (board == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL!!!\n");
        fmt::print("RES:\n");
        for (const auto& t : board) {
            fmt::print("{}\n", t);
        }
        fmt::print("ans:\n");
        for (const auto& t : ans) {
            fmt::print("{}\n", t);
        }
    }

}
int main() {
    test({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}}, {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}} );
    test({{1, 1}, {1, 0}} , {{1, 1}, {1, 1}} );

    return 0;
}
