#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include"Tree.h"
using namespace std;
class Solution {
private:
    vector<string> ans;
    vector<int> path;
    void dfs(TreeNode* node) {
        path.emplace_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            generateString(path);
            path.pop_back();
            return;
        }

        if (node->left != nullptr) {
            dfs(node->left);
        }
        if (node->right != nullptr) {
            dfs(node->right);
        }
        path.pop_back();
    }

    void generateString(vector<int>& path) {
        stringstream ss;
        ss << path[0];
        for (int i = 1; i < path.size(); i++)
        {
            ss << "->" << path[i];
        }
        ans.emplace_back(ss.str());
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        ans = vector<string>();
        path = vector<int>();
        if (root != nullptr) {
            dfs(root);
        }
        return ans;
    }
};