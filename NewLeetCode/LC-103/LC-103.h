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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> que;
        vector<vector<int>> result;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            vector<int> level(n);

            if (result.size() % 2) {
                //偶数层，根相当于第1层
                for (int i = n - 1; i >= 0; --i) {
                    TreeNode* curNode = que.front();
                    que.pop();
                    level[i] = curNode->val;
                    if (curNode->left) { que.push(curNode->left); }
                    if (curNode->right) { que.push(curNode->right); }
                }
            }
            else {
                //奇数层
                for (int i = 0; i < n; ++i) {
                    TreeNode* curNode = que.front();
                    que.pop();
                    level[i] = curNode->val;
                    if (curNode->left) { que.push(curNode->left); }
                    if (curNode->right) { que.push(curNode->right); }
                }
            }
            result.emplace_back(level);
        }
        return result;
    }
};
