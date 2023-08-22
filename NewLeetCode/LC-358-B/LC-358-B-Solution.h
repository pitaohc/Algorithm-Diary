//
// Created by devcpp on 23-8-15.
//

#ifndef LC_540_SOLUTION_H
#define LC_540_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
#include"List.h"
#include<vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = head;
        vector<int> nums;
        nums.reserve(1e4 + 5);
        while (cur != nullptr) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        int jinwei = 0;
        ListNode* newHead = nullptr;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int temp = (nums[i] << 1) + jinwei;
            jinwei = temp / 10;
            nums[i] = temp % 10;
            newHead = new ListNode(temp % 10, newHead);
        }
        if (jinwei != 0) {
            newHead = new ListNode(jinwei, newHead);
        }
        return newHead;


    }
};
#endif //LC_540_SOLUTION_H
