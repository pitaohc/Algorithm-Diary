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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) { return {}; }
        vector<vector<int>> result;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = que.front();
                que.pop();
                level[i] = node->val;
                if (node->left) { que.push(node->left); }
                if (node->right) { que.push(node->right); }
            }
            result.emplace_back(move(level));
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
