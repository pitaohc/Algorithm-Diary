#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include"Tree.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxDiameter = 0;
    int depth(TreeNode* node) {
        if (node == nullptr) { return 0; }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
#ifdef _DEBUG
        fmt::print("cur val: {}, left depth: {}, right depth: {}, diameter:{}, max: {}\n",
            node->val, leftDepth, rightDepth, leftDepth + rightDepth, maxDiameter);
#endif // _DEBUG

        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;
    }
};