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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                //list1 smaller
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
#ifdef _DEBUG
            cout << "list: " << head << endl;
#endif // _DEBUG
            cur = cur->next;
        }
        cur->next = (list1 != nullptr) ? list1 : list2;
        cur = head->next;
        delete head; //释放额外存储的头节点
        return cur;
    }
};
