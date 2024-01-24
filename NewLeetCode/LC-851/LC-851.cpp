#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-851.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<vector<int>> richer, vector<int> quiet,vector<int> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("richer: {}\n", richer);
    fmt::print("quiet: {}\n", quiet);
    auto res = sol.loudAndRich(richer,quiet);
    if(ans == res) {
        fmt::print(fg(fmt::color::green), "Pass test\n");
    } else {
        fmt::print(fg(fmt::color::red), "Fail test\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Got: {}\n", res);
    }
    cout << endl;
}
int main() {
    test({{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}} ,
        {3, 2, 5, 4, 6, 1, 7, 0},
        {5, 5, 2, 5, 4, 5, 6, 7}
    );
    test({},
        {0},
        {0}
    );

    return 0;
}
