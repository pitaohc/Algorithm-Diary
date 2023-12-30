#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-101.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

bool test(const vector<int> nums, bool ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    TreeNode* root = buildTree(nums);
    fmt::print("tree: {}\n", to_string(root));
    bool res = sol.isSymmetric(root);
    fmt::print("ans = {}, res = {}, is Correct ? {}\n", ans, res, ans == res);
    deleteTree(root);
    return ans == res;
}

int main() {
    test({ 1,2,3 }, false);
    test({ 1,2,2,3,4,4,3 }, true);
    test({ 1,2,2,null,3,null,3 }, false);
    return 0;
}
