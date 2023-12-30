#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
private:
    void helper(TreeNode*& root, unordered_set<int>& to_delete, vector<TreeNode*>& forest) {
        if (root == nullptr) {
            return ;
        }
        helper(root->left, to_delete, forest);
        helper(root->right, to_delete, forest);
        if (to_delete.find(root->val) != to_delete.end()) {
            if (root->left != nullptr) {
                forest.push_back(root->left);
            }
            if (root->right != nullptr) {
                forest.push_back(root->right);
            }
            delete root;
            root = nullptr;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) {
            return {};
        }
        vector<TreeNode*> forest;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        helper(root, to_delete_set, forest);
        if (root != nullptr) {
            forest.emplace_back(root);
        }
        return forest; 
    }
};

