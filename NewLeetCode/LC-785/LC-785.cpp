#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-785.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<vector<int>> graph, bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("Graph: {}\n", graph);
    bool res = sol.isBipartite(graph);
    fmt::print("Ans = {}, Res = {}, is Correct ? {}\n", ans, res, ans == res);

}
int main() {

    test({ {1},{0,3},{3},{1,2} }, true);
    return 0;
}
