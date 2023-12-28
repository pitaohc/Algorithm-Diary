#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        TreeNode* newRoot = nullptr;
        if (root->val < low) {
            newRoot = root->right;
            //delete root;
            root = nullptr;
        }
        else if (root->val > high) {
            newRoot = root->left;
            //delete root;
            root = nullptr;
        }
        else {
            newRoot = root;
        }
        return newRoot;
    }
};

