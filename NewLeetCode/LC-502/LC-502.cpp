#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-502.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    int k, int w, vector<int> profits, vector<int> capital, int ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: k = {}, w = {}, profits = {}, capital = {}\n", k, w, profits, capital);


    auto res = sol.findMaximizedCapital(k, w, profits, capital);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }


}
int main() {
    system("chcp 65001");
    test(2, 0, { 1,2,3 }, { 0,1,1 }, 4);
    test(3, 0, { 1,2,3 }, { 0,1,2 }, 6);
    test(1, 0, { 5,5,5 }, { 4,3,2 }, 0); //无可投资项目


    return 0;
}
