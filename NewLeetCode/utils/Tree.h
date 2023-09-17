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

TreeNode* buildTree(std::vector<int>& nodes) {
    if (nodes.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) { // 层序遍历
        TreeNode* node = q.front();
        q.pop();
        if (nodes[i] != 0) { // 0 means null,插入左子树
            node->left = new TreeNode(nodes[i]);
            q.push(node->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != INT_MIN) { // 插入右子树
            node->right = new TreeNode(nodes[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

/*
* 删除子树
*/
void deleteTree(TreeNode* head) {
    std::queue<TreeNode*> q;
    q.push(head);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        delete node;
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