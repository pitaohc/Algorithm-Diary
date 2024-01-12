#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-797.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

bool judge(vector<vector<int>> res, vector<vector<int>> ans) {
    if (res.size() != ans.size()) return false;
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() != ans[i].size()) return false;
        for (int j = 0; j < res[i].size(); j++) {
            if (res[i][j] != ans[i][j]) return false;
        }
    }
    return true;
}

void test(vector<vector<int>> graph, vector<vector<int>> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: {}\n", graph);
    auto res = sol.allPathsSourceTarget(graph);
    if (judge(res, ans)) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
        fmt::print("Output: {}\n", res);
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Output: {}\n", res);
        fmt::print("Expected: {}\n", ans);
    }
    cout << endl;
}
int main() {
    test({ {1,2},{3},{3},{} }, { {0,1,3},{0,2,3} });
    test({ {4, 3, 1}, {3, 2, 4}, {3}, {4}, {} }, { {0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4} });

    return 0;
}
