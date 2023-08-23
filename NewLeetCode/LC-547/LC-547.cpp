//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "LC-547-Solution.h"
using namespace std;

int main() {
    Solution sol;
    vector<vector<int>> isConnected;
    int caseNum, res, ans;

    caseNum = 1;
    isConnected = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
    ans = 2;
    res = sol.findCircleNum(isConnected);
    fmt::print("Case {}\n"
        "isConnected:\n"
        "{}\n"
        "ans = {}, res = {}\n",
        caseNum, isConnected, ans, res);
    cout << endl;

    caseNum = 2;
    isConnected = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    ans = 3;
    res = sol.findCircleNum(isConnected);
    fmt::print("Case {}\n"
        "isConnected:\n"
        "{}\n"
        "ans = {}, res = {}\n",
        caseNum, isConnected, ans, res);
    cout << endl;

    caseNum = 3;
    isConnected = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    ans = 1;
    res = sol.findCircleNum(isConnected);
    fmt::print("Case {}\n"
        "isConnected:\n"
        "{}\n"
        "ans = {}, res = {}\n",
        caseNum, isConnected, ans, res);
    cout << endl;

    //[[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]

    caseNum = 4;
    isConnected = { {1,0,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,1,1} };
    ans = 1;
    res = sol.findCircleNum(isConnected);
    fmt::print("Case {}\n"
        "isConnected:\n"
        "{}\n"
        "ans = {}, res = {}\n",
        caseNum, isConnected, ans, res);
    cout << endl;

    return 0;
}