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
    int pathSumFromRoot(TreeNode* root, long long  targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int count = (root->val == targetSum);

        count += pathSumFromRoot(root->left, targetSum - root->val);
        count += pathSumFromRoot(root->right, targetSum - root->val);
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        return root ?
            pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSumFromRoot(root, targetSum) :
            0;
    }
};