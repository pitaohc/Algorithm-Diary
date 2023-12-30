#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<Tree.h>
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
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        if (leftDepth == -1 || rightDepth == -1) {
            return -1;
        }
        return abs(leftDepth - rightDepth) <= 1 ? max(leftDepth, rightDepth) + 1 : -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) >= 0;
    }
};
