#pragma once
#include"stdc++.h"

//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* _next = NULL) :val(x), next(_next) {}
};

std::ostream& operator<<(std::ostream& out, ListNode* head);

ListNode* NodeFactory(const std::vector<int>& nums);