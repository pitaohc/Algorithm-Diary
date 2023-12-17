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
    using Node = ListNode*;
private:
    Node findMiddle(Node head) {
        Node fast = head, slow = head;
        while (fast->next!=nullptr && fast->next->next!=nullptr) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        return slow;
    }
    Node reverse(Node head) {
        Node prev = nullptr;
        while (head != nullptr) {
            Node next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            throw "ListNode is nullptr";
        }
#ifdef _DEBUG
        cout << "original: " << head << endl;
#endif // _DEBUG

        //找到中间节点
        Node mid = findMiddle(head);
        Node rightPart = mid->next;
        mid->next = nullptr;
#ifdef _DEBUG
        cout << "half list: " << rightPart << endl;
#endif // _DEBUG
        //翻转后半部分链表
        rightPart = reverse(rightPart);
        //mid = nullptr;
#ifdef _DEBUG
        cout << "left half list: " << head << endl;
        cout << "reversed half list: " << rightPart << endl;
#endif // _DEBUG

        //判断是否回文
        bool result = true;
        Node leftCur = head, rightCur = rightPart;
        while (rightCur != nullptr) {
            if (leftCur->val != rightCur->val) {
                result = false;
                break;
            }
            leftCur = leftCur->next;
            rightCur = rightCur->next;
        }
        //修复链表
        rightPart = reverse(rightPart);
        mid->next = rightPart;
#ifdef _DEBUG
        cout << "fixed right: " << rightPart<<endl;
        cout << "total list: " << head << endl;
#endif // _DEBUG

        return result;
    }
};