#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-149.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> points;
    int res, ans;
    fmt::print("Case {}\n", caseNum++);
    points = { {0, 0}, {4, 5}, {7, 8}, {8, 9}, {5, 6}, {3, 4}, {1, 1} };
    ans = 5;
    fmt::print("points: {}\n"
        "ans = {}\n", points, ans);
    res = sol.maxPoints(points);
    fmt::print("res = {}\n", res);

    return 0;
}
