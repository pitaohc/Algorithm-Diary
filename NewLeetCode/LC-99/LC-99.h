#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
    using Node = TreeNode*;
private:
    void inorder(Node node, Node& m1, Node& m2, Node& prev) {
        if (node == nullptr) {
            return;
        }
        //left
        if (node->left != nullptr) {
            inorder(node->left, m1, m2, prev);
        }
        //mid
        if (prev && node->val < prev->val) {
            //找到错误
            if (!m1) {
                m1 = prev;
                m2 = node;
            }
            else {
                m2 = node;
            }
        }
        //right
        prev = node;
        if (node->right != nullptr) {
            inorder(node->right, m1, m2, prev);
        }

    }
public:
    void recoverTree(Node root) {
        Node m1 = nullptr, m2 = nullptr, prev = nullptr;
        inorder(root, m1, m2, prev);
        if (m1 != nullptr && m2 != nullptr) {
            int temp = m1->val;
            m1->val = m2->val;
            m2->val = temp;
        }
    }
};
