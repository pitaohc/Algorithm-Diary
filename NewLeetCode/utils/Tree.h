#pragma once
#ifndef TREE_H
#define TREE_H


#include<vector>
#include<queue>
#include<fmt/core.h>
#include<fmt/ranges.h>
#include<fmt/color.h>

constexpr int PRINTBUFFERSIZE = 2048;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/// <summary>
/// 串行化构建树结构,
/// 使用NULL或0表示空节点
/// </summary>
/// <param name="nodes">串行化的数组</param>
/// <returns>树的根节点</returns>
/*
Example:
[] Empty tree.

[1, 2, 3]
  1
 / \
2   3

[1, null, 2, 3]
     1
      \
       2
      /
     3

[5, 4, 7, 3, null, 2, null, -1, null, 9]
      5
     / \
    4   7
   /   /
  3   2
 /   /
-1  9
*/
TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.size() == 0 || nodes[0] == 0) { return nullptr; }
    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (nodes[i] != NULL) {// 0 means null,插入左子树
            node->left = new TreeNode(nodes[i]);
            q.push(node->left);
        }
        ++i;
        if (i < nodes.size() && nodes[i] != NULL) {
            node->right = new TreeNode(nodes[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

/// <summary>
/// 删除树，使用BFS方法删除树
/// </summary>
/// <param name="root">待删除树的根节点</param>
void deleteTree(TreeNode* root) {
    if (root == nullptr) { return; }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        delete node;
        node = nullptr;
    }

}
/// <summary>
/// 输出树的序列化字符串
/// </summary>
/// <param name="root"></param>
/// <returns></returns>
std::string to_string(TreeNode* root) {
    if (root == nullptr) return "{}";
    using std::string;
    using std::stringstream;
    using std::queue;
    stringstream ss;
    ss << '{';
    ss << root->val;
    queue<TreeNode*> q;
    if (root->left != nullptr || root->right != nullptr)
    {
        //如果是叶子节点就不存储子节点
        q.push(root->left);
        q.push(root->right);
    }
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        ss << ", ";
        if (node == nullptr) {
            ss << "NULL";
        }
        else {
            ss << node->val;
            if (node->left != nullptr || node->right != nullptr)
            {
                //如果是叶子节点就不存储子节点
                q.push(node->left);
                q.push(node->right);
            }
        }
    }

    ss << '}';
    return ss.str();
}

#endif