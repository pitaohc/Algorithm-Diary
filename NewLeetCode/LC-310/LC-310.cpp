#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-310.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(int n, vector<vector<int>> edges, vector<int> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    vector<int> res;
    res = sol.findMinHeightTrees(n, edges);
    fmt::print("n: {}\n"
        "edges: {}\n"
        "ans: {}\n"
        "res: {}\n", n, edges, ans, res);
    if (res == ans) {
        fmt::print(fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fg(fmt::color::red), "Fail\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Got: {}\n", res);
    }
    cout << endl;
}

int main() {
    test(4, { {1,0},{1,2},{1,3} }, { 1 });
    test(6, { {3,0} ,{3,1},{3,2},{3,4},{5,4} }, { 3,4 });
    test(1, {}, { 0 });
    return 0;
}
