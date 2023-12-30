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
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        //0. ���right<left˵���ڵ�Ϊ�գ�ֱ�ӷ���
        if (pre_right < pre_left) {
            return nullptr;
        }
        //1. ��ǰ�������ҵ���һ���ڵ㣬�ýڵ��ǵ�ǰ�����ĸ��ڵ�
        int val = preorder[pre_left];
        //2. ������ڵ�
        TreeNode* root = new TreeNode(val);
        //3. �����������ҵ��ýڵ��λ�ã���ʣ��ڵ�ֳ�������������
        int in_pos = inorder[val];
        int left_size = in_pos - in_left;
        int right_size = in_right - in_pos;
        //4. �ݹ飬��������
        root->left = buildTree(preorder, inorder, 
            pre_left + 1, pre_left + left_size, 
            in_left, in_pos - 1);
        root->right = buildTree(preorder, inorder,
            pre_left + left_size + 1, pre_right,
            in_pos + 1, in_right);
        
        //5. ����
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> um;
        for (size_t i = 0; i < inorder.size(); i++)
        {
            um[inorder[i]] = i;
        }
        return preorder.empty() ? nullptr : 
            buildTree(preorder, um, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
