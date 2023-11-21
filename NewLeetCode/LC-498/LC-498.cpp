#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-498.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> mat;
    vector<int> ans, res;

    fmt::print("Case {}\n", caseNum++);
    mat = {
        {1,2,3,},
        {4,5,6,},
        {7,8,9,},
    };
    ans = { 1,2,4,7,5,3,6,8,9 };
    fmt::print("mat:\n{}\n"
        "ans = {}\n", mat, ans);
    res = sol.findDiagonalOrder(mat);
    fmt::print("res = {}\n", res);


    fmt::print("Case {}\n", caseNum++);
    mat = {
        {1,2,},
        {4,5,},
        {7,8,},
    };
    ans = { 1,2,4,7,5,8 };
    fmt::print("mat:\n{}\n"
        "ans = {}\n", mat, ans);
    res = sol.findDiagonalOrder(mat);
    fmt::print("res = {}\n", res);


    fmt::print("Case {}\n", caseNum++);
    mat = {
        {1,2,3,},
        {7,8,9,},
    };
    ans = { 1,2,7,8,3,9 };
    fmt::print("mat:\n{}\n"
        "ans = {}\n", mat, ans);
    res = sol.findDiagonalOrder(mat);
    fmt::print("res = {}\n", res);

    return 0;
}
