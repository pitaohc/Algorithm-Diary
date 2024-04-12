#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode* less = nullptr;
        ListNode* greater = nullptr;
        ListNode* cur = head;
        ListNode* lessHead = nullptr;
        ListNode* greaterHead = nullptr;
        while (cur != nullptr) {
            if (cur->val < x) {
                if (lessHead == nullptr) {
                    less = lessHead = cur;

                }
                else {
                    less->next = cur;
                    less = cur;
                }
            }
            else {
                if (greaterHead == nullptr) {
                    greater = greaterHead = cur;
                }
                else {
                    greater->next = cur;
                    greater = cur;
                }
            }

            cur = cur->next;
        }

        if (less == nullptr) {
            return greaterHead;
        }
        else if (greater == nullptr) {
            return lessHead;
        }
        else {
            less->next = greaterHead;
            greater->next = nullptr;
            return lessHead;
        }
    }
};
