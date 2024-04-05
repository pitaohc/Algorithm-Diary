#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-42.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(vector<int> height,int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: \n{}\n", height);
    int res = sol.trap(height);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "PASS\n");
    } else{
        fmt::print(fmt::fg(fmt::color::red), "FAIL\n");
        fmt::print("Expected: {}\n", ans);
        fmt::print("Returned: {}\n", res);
    }
}
int main() {
    test({ 2,2 }, 0);
    test({ 11,1,11 }, 10);
    test({ 11,2,1,11 }, 19);
    test({ 11,1,1,11 }, 20);
    test({ 0,1,0,2,1,0,1,3,2,1,2,1 }, 6);
    test({ 4,2,0,3,2,5 }, 9);
    test({ 4,2,0,3,2,3 }, 5);
    test({ 3,2,1 }, 0);
    test({ 1,2,3 }, 0);


    return 0;
}
