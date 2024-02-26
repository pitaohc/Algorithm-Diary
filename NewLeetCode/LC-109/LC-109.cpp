#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-109.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<int> nums, vector<int> tree_nums) {
    Solution sol;
    int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);

    ListNode* list = NodeFactory(nums);
    cout << list << endl;
    TreeNode* ans = buildTree(tree_nums);
    cout << to_string(ans) << endl;

    TreeNode* res = sol.sortedListToBST(list);
    cout << to_string(res) << endl;
}
int main() {
    test({ -10,-3,1,5,9 }, { 1,-3,9,-10,0,5 });


    return 0;
}
