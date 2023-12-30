#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-669.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<int> nums, int low, int high, vector<int> ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    TreeNode* root = buildTree(nums);
    fmt::print("tree: {}, low = {}, high = {}\n", to_string(root), low, high);

    root = sol.trimBST(root, low, high);
    fmt::print("trimed tree: {}\n", to_string(root));
    fmt::print("ans tree: {}\n", ans);
    deleteTree(root);

}
int main() {
    test({ 1,null,2 }, 2, 4, { 2 });

    return 0;
}
