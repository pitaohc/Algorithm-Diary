#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-427.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<vector<int>> grid) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    for (const auto& line : grid) {
        fmt::print("{}\n", line);
    }
    Node* res = sol.construct(grid);
    printNode(res);
}
int main() {
    test({
        {0,0,1,1},
        {1,1,0,0},
        {0,0,1,1},
        {1,1,0,0}, });

    test({
    {0,0,1,1},
    {0,0,1,1},
    {1,0,1,1},
    {0,1,1,1}, });
    test({ {0,0},{0,0} });



    return 0;
}
