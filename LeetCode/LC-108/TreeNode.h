#pragma once
class TreeNode
{
public:
    int val;
    TreeNode* left, * right;
    TreeNode();
    TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr);
};

