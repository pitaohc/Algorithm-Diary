#pragma once
#include"stdc++.h"
#include"List.h"
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* fast, * slow;
        fast = slow = head;
        do
        {
            if (fast != NULL)
                fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            if (slow != NULL)
                slow = slow->next;

        } while (fast != nullptr && slow != nullptr && fast != slow);

        if (fast == nullptr || slow == nullptr) return nullptr; //不存在环

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};