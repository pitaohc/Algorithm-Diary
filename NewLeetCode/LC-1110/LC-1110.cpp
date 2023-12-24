#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1110.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
bool test(const vector<int> tree, vector<int> to_delete) {
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    TreeNode* root = buildTree(tree);
    cout << to_string(root) << endl;
    Solution sol;
    auto res = sol.delNodes(root, to_delete);
    cout << "{";
    for_each(res.begin(), res.end(), [](TreeNode* node) {cout << to_string(node); });
    cout << "}\n";
    return true;
}

int main() {
    test({ 1,2,3,4,5,6,7 }, { 3,5 });
    test({ 1,2,4,null,3 }, { 3 });

    return 0;
}
