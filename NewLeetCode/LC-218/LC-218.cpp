#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-218.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> buildings;
    vector<vector<int>> ans, res;
    fmt::print("Case {}\n", caseNum++);
    buildings = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    ans = { {2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0} };
    fmt::print("buildings: \n"
        "{}\n", buildings);
    fmt::print("ans: \n"
        "{}\n", ans);
    res = sol.getSkyline(buildings);
    fmt::print("res: \n"
        "{}\n", res);
    return 0;
}
