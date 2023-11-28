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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using Node = ListNode*;
        auto cmp = [](Node left, Node right) -> bool {
            return left->val > right->val;
            };
        if (lists.empty())
        {
            return nullptr;
        }
        priority_queue<Node, vector<Node>, decltype(cmp)> pq;
        for (Node list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        if (pq.empty()) {
            return nullptr;
        }
        Node head = pq.top(), cur = head;
        pq.pop();
        if (head->next != nullptr) {
            pq.push(head->next);
        }
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next != nullptr) {
                pq.push(cur->next);
            }
        }
        return head;
    }
};