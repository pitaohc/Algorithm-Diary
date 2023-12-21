#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-437.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
#define null NULL
using namespace std;

bool test(vector<int> nums, int targetSum, int ans) {
    static int caseNum = 1;
    Solution sol;
    TreeNode* root = nullptr;
    int res;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    root = buildTree(nums);
    fmt::print("Tree: {}\n", to_string(root));
    res = sol.pathSum(root, targetSum);
    fmt::print("Output: {}, Answer: {}, ", res, ans);
    fmt::print(fmt::fg((res == ans) ? fmt::color::green : fmt::color::red), "Correct? {}\n\n", res == ans);
    deleteTree(root);
    return res == ans;
}


int main() {

    test({ 10, 5, -3, 3, 2, null, 11, 3, -2, null, 1 }, 8, 3);
    test({ 5,4,8,11,null,13,4,7,2,null,null,5,1 }, 22, 3);
    test({ 1,1,1 }, 2, 2);
    test({ 1 }, 2, 0);
    test({ 1,-1,-1 }, 0, 2);
    return 0;
}
