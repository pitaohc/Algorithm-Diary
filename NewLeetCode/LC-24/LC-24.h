#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        using Node = ListNode*;
        Node prev = nullptr, cur = head, cur1, next;
        while (cur != nullptr && cur->next != nullptr) {
            cur1 = cur->next;
            next = cur1->next;

            cur->next = next;
            cur1->next = cur;
            if (prev != nullptr) { 
                prev->next = cur1;
            }
            else {// 特判第一次情况
                head = cur1;
            }

            prev = cur;
            cur = next;
        }
        return head;
    }
};
