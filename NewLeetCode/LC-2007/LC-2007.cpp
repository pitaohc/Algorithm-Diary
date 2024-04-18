#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-2007.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    vector<int> changed,
    vector<int> ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: {}\n", changed);


    auto res = sol.findOriginalArray(changed);
    sort(res.begin(), res.end());
    sort(ans.begin(), ans.end());
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
    test({ 6,3,0,1 }, {});
    test({ 0,0,0,0 }, { 0,0 });
    test({ 1,3,4,2,6,8 }, { 1,4,3 });
    test({ 0,1 }, {});
    test({ 1,2,2,4,4,8 }, { 1,2,4 });
    return 0;
}
