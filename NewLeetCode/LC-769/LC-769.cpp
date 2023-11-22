#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-769.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> arr;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    arr = { 4,3,2,1,0 };
    ans = 1;
    res = sol.maxChunksToSorted(arr);
    fmt::print("arr = {}\n"
        "ans = {}, res = {}\n", arr, ans, res);

    fmt::print("Case {}\n", caseNum++);
    arr = { 1,0,2,3,4 };
    ans = 4;
    res = sol.maxChunksToSorted(arr);
    fmt::print("arr = {}\n"
        "ans = {}, res = {}\n", arr, ans, res);

    fmt::print("Case {}\n", caseNum++);
    arr = { 1,3,2,0,4 };
    ans = 2;
    res = sol.maxChunksToSorted(arr);
    fmt::print("arr = {}\n"
        "ans = {}, res = {}\n", arr, ans, res);

    return 0;
}
