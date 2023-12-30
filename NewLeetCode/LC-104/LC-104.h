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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        using Node = TreeNode*;
        int depth = 0;
        queue<Node> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size > 0) {
                Node front = que.front();
                que.pop();
                if (front->left != nullptr) {
                    que.push(front->left);
                }
                if (front->right != nullptr) {
                    que.push(front->right);
                }
                --size;
            }
            ++depth;
        }
        return depth;
    }
};
