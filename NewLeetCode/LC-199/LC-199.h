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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return { };
        }
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            res.push_back(que.front()->val); // 第一个元素，因为从右往左遍历，所以是最右的元素
            while (n-- > 0) {
                TreeNode* node = que.front();
                que.pop();
                if (node->right != nullptr) { // 从右往左遍历
                    que.push(node->right);
                }
                if (node->left != nullptr) {
                    que.push(node->left);
                }

            }
        }
        return res;
    }
};
