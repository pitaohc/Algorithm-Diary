#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-399.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

bool compareVector(vector<double> v1, vector<double> v2) {
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); ++i) {
        if (abs(v1[i] - v2[i]) > 1e-4) return false;
    }
    return true;
}

void test(vector<vector<string>> equations, vector<double> values, vector<vector<string>> queries, vector<double> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("Input: \n"
        "  equations = {}\n"
        "  values    = {}\n"
        "  queries   = {}\n", equations, values, queries);
    auto res = sol.calcEquation(equations, values, queries);
    if (compareVector(res, ans)) {
        fmt::print(fg(fmt::color::green), "Pass\n", res);
    }
    else {
        fmt::print(fg(fmt::color::red), "Fail\n", res);
        fmt::print("Expected: {}\n", ans);
        fmt::print("Actual:   {}\n", res);
    }
}

int main() {
    test(
        { {"a", "b"}, {"e", "f"}, {"b", "e"} },
        { 3.4, 1.4, 2.3 },
        { {"b", "a"}, {"a", "f"}, {"f", "f"}, {"e", "e"}, {"c", "c"}, {"a", "c"}, {"f", "e"} },
        { 0.29412, 10.948, 1.0, 1.0, -1.0, -1.0, 0.71429 }
    );
    test(
        { {"a","b"},{"b","c"} },
        { 2.0,3.0 },
        { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} },
        { 6.00000,0.50000,-1.00000,1.00000,-1.00000 });

    test(
        { {"a","e"},{"b","e"} },
        { 4.0,3.0 },
        { {"a", "b"}, {"e", "e"}, {"x", "x"} },
        { 1.33333,1.0,-1.0 }
    );

    return 0;
}
