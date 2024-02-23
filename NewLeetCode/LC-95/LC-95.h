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
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return { nullptr };
        }
        vector<TreeNode*> allTrees;
        // 枚举可行根节点
        for (int i = start; i <= end; ++i) {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (const auto& left : leftTrees) {
                for (const auto& right : rightTrees) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left;
                    cur->right = right;
                    allTrees.emplace_back(cur);
                }
            }
        }
        return allTrees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return (n == 0) ? vector<TreeNode*>() : generateTrees(1, n);
    }
};

