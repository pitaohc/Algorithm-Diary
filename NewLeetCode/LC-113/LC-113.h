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
private:
    vector<vector<int>> result;
    vector<int> path;
    void getPath(TreeNode* root, int targetSum) {
        if (root->left == nullptr && root->right == nullptr) { // 到达叶子节点
#ifdef _DEBUG
            fmt::print("arrive leaf, path = {}, targetSum = {}\n", path, targetSum);
#endif // _DEBUG
            if (targetSum == root->val) { // 剩余值为0
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);
#ifdef _DEBUG
        fmt::print(fmt::fg(fmt::color::green), "into {}, path = {}\n", root->val, path);
#endif // _DEBUG

        if(root->left) getPath(root->left, targetSum - root->val);
        if(root->right) getPath(root->right, targetSum - root->val);

        path.pop_back();
#ifdef _DEBUG
        fmt::print(fmt::fg(fmt::color::red),"quit {}, path = {}\n", root->val, path);
#endif // _DEBUG
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        getPath(root, targetSum);
        return result;
    }
};