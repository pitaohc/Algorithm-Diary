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
/*
* 输出树
* 格式为
*     123
*     / \
*    11 1234
*    /  /  \
* -100  1  12
*      / \
*     15 21
*/
void printTree(TreeNode* root) {

    /*
    if (root == nullptr) {
        fmt::print(fmt::fg(fmt::color::red), "Empty Tree\n");
    }
    int depth = 0;
    //计算树高度
    function<int(TreeNode*)> getDepth = [&](TreeNode* node) -> int {
        if (node == 0) return 0;

        return std::max(getDepth(node->left), getDepth(node->right)) + 1;
    };
    //根据高度构建输出缓冲区
    depth = getDepth(root);
    //fmt::print("depth = {}\n", depth);
    std::vector<std::string> buffers(depth * 2 - 1);
    std::for_each(buffers.begin(), buffers.end(), [](std::string& buffer) {buffer.reserve(PRINTBUFFERSIZE + 1); });

    function<int(TreeNode*, int, int)> printNode = [&](TreeNode* node, int level, int beginPos = 0) ->int {
        if (node == nullptr) return 0;
        //后序遍历
        int leftCharNum = 0, rightCharNum = 0;
        if (node->left) {
            leftCharNum = printNode(node->left, level + 1, beginPos);
        }
        if (node->right)
        {
            rightCharNum = printNode(node->right, level + 1, beginPos + leftCharNum + 1);
        }

    };
    */
}

#endif