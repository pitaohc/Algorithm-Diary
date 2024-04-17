#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        function<TreeNode* (TreeNode*)> dfs = [&](TreeNode* node)->TreeNode* {
            if (node == nullptr) return nullptr;
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            //变形为后序遍历
            TreeNode* lefttail = dfs(left); //左子树链表
            TreeNode* righttail = dfs(right); // 右子树链表
            node->left = nullptr;
            TreeNode* tail = node; //当前树链表的尾巴
            if (left == nullptr && right == nullptr) {
                //叶子节点
            }
            else if (left != nullptr && right == nullptr) {
                //右节点不存在
                node->right = left;
                tail = lefttail;
            }
            else if (left == nullptr && right != nullptr) {
                //左节点不存在
                node->right = right;
                tail = righttail;
            }
            else {
                //中间节点
                node->right = left;//左子树接入当前节点
                lefttail->right = right; // 右子树接在左子树的尾巴上
                tail = righttail;
            }
            return tail;
            };
        dfs(root);
    }
};
