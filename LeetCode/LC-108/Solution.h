#pragma once
#include"stdc++.h"
#include"List.h"
#include "TreeNode.h"
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return createNode(nums, 0, nums.size() - 1);
    }
    TreeNode* createNode(const std::vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        else if (left == right) return new TreeNode(nums[left]);
        else {
            int mid = left + (right - left) / 2;
            return new TreeNode(nums[mid],
                createNode(nums, left, mid - 1),
                createNode(nums, mid + 1, right));
        }


    }
};