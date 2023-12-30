#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-543.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;

    TreeNode* root;
    vector<int> builder;
    int res, ans;

    fmt::print("Case {}\n", caseNum++);
    builder = { 1,2,3,4,5 };
    root = buildTree(builder);
    ans = 3;
    res = sol.diameterOfBinaryTree(root);
    fmt::print("ans = {}, res = {}, correct: {}", ans, res, ans == res);
    deleteTree(root);

    fmt::print("Case {}\n", caseNum++);
    builder = { 1,2 };
    root = buildTree(builder);
    ans = 1;
    res = sol.diameterOfBinaryTree(root);
    fmt::print("ans = {}, res = {}, correct: {}", ans, res, ans == res);
    deleteTree(root);

    fmt::print("Case {}\n", caseNum++);
    builder = { 1,2,0,4,5,0,0,8,0,0,11 };
    root = buildTree(builder);
    ans = 4;
    res = sol.diameterOfBinaryTree(root);
    fmt::print("ans = {}, res = {}, correct: {}", ans, res, ans == res);
    deleteTree(root);

    return 0;
}
