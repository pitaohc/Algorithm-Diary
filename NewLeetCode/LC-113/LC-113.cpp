#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-113.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<int> nums, int targetSum) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);

    TreeNode* root = buildTree(nums);
    cout << to_string(root) << endl;
    auto res = sol.pathSum(root, targetSum);
    fmt::print("result: {}\n", res);
}
int main() {
    test({ -2,null,-3 }, -5);
    test({ 5,4,8,11,null,13,4,7,2,null,null,5,1 }, 22);
    return 0;
}
