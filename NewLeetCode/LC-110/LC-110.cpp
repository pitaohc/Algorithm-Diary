#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-110.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    vector<int> input,
    bool ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: {}\n", input);

    auto root = buildTree(input);
    auto res = sol.isBalanced(root);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }


}
int main()
{
    test({1,null,2,null,3},false);
    test({3, 9, 20, null, null, 15, 7}, true);
    test({1, 2, 2, 3, 3, null, null, 4, 4}, false);
    test({}, true);


    return 0;
}
