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
private:
    template <class _Ty, class _Container = vector<_Ty>, class _Pr = less<typename _Container::value_type>>
    void addListtoQueue(priority_queue<_Ty, _Container, _Pr>& pq, ListNode* const head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            pq.push(cur->val);
            cur = cur->next;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>> pq;
        for (ListNode* const list : lists) {
            addListtoQueue(pq, list);
        }
        ListNode* head = nullptr;
        while (!pq.empty()) {
            head = new ListNode(pq.top(), head);
            pq.pop();
        }
        return head;
    }
};