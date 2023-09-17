#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-257.h"
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "Tree.h"
#define null NULL
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    TreeNode* root;
    vector<string> res, ans;


    fmt::print("Case {}\n", caseNum++);
    root = buildTree(vector<int>{ 1, 2, 3, null, 5 });
    res = sol.binaryTreePaths(root);
    fmt::print("{}\n", res);
    deleteTree(root);

    fmt::print("Case {}\n", caseNum++);
    root = buildTree(vector<int>{ 1 });
    res = sol.binaryTreePaths(root);
    fmt::print("{}\n", res);
    deleteTree(root);


    return 0;
}
