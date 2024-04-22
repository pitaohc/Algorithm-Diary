#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
    //private:
    //    void handle(Node*& last, Node*& p, Node*& nextStart) {
    //        if (last) {
    //            last->next = p;
    //        }
    //        if (!nextStart) {
    //            nextStart = p;
    //        }
    //        last = p; //链表后移
    //    }
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* start = root;
        while (start) {
            Node* last = nullptr, * nextStart = nullptr;
            for (Node* p = start; p != nullptr; p = p->next) {
                if (p->left) {
                    //handle(last, p->left, nextStart);
                    if (last) {
                        last->next = p->left;
                    }
                    if (!nextStart) {
                        nextStart = p->left;
                    }
                    last = p->left; //链表后移
                }
                if (p->right) {
                    //handle(last, p->right, nextStart);
                    if (last) {
                        last->next = p->right;
                    }
                    if (!nextStart) {
                        nextStart = p->right;
                    }
                    last = p->right; //链表后移
                }
            }
            start = nextStart;
        }

        return root;
    }
};
