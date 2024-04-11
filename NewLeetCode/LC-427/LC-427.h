#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;




// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

void printNode(const Node* root, int depth = 0) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << (root->isLeaf ? "leaf" : "node") << " " << root->val << endl;
    printNode(root->topLeft, depth + 1);
    printNode(root->topRight, depth + 1);
    printNode(root->bottomLeft, depth + 1);
    printNode(root->bottomRight, depth + 1);

}

class Solution {
private:
    vector<vector<int>> grid;
    Node* dfs(int x1, int y1, int x2, int y2) {
        if (x1 == x2 && y1 == y2) {
            //单个格子
#ifdef _DEBUG
            fmt::print("leaf at [{},{}]\n", x1, y1);
#endif // _DEBUG

            return new Node{ grid[x1][y1] == 1,true };
        }
#ifdef _DEBUG
        fmt::print("into [{},{}], [{},{}]\n", x1, y1, x2, y2);
#endif // _DEBUG

        Node* node = new Node{ false,false };
        int sum = 0;
        int leafCnt = 0;
        int midx = (x2 - x1) / 2 + x1;
        int midy = (y2 - y1) / 2 + y1;
        node->topLeft = dfs(x1, y1, midx, midy);
        node->topRight = dfs(x1, midy + 1, midx, y2);
        node->bottomLeft = dfs(midx + 1, y1, x2, midy);
        node->bottomRight = dfs(midx + 1, midy + 1, x2, y2);

        sum = node->topLeft->val + node->topRight->val + node->bottomLeft->val + node->bottomRight->val;
        leafCnt = node->topLeft->isLeaf + node->topRight->isLeaf + node->bottomLeft->isLeaf + node->bottomRight->isLeaf;

        if (leafCnt == 4 && (sum == 0 || sum == 4)) {
#ifdef _DEBUG
            fmt::print("merge [{},{}], [{},{}], val = {}, leafCnt = {}\n", x1, y1, x2, y2, sum, leafCnt);
#endif // _DEBUG

            //当前区块可以合并
            node->isLeaf = true;
            node->val = node->topLeft->val;
            delete node->topLeft;
            delete node->topRight;
            delete node->bottomLeft;
            delete node->bottomRight;

            node->topLeft = nullptr;
            node->topRight = nullptr;
            node->bottomLeft = nullptr;
            node->bottomRight = nullptr;
        }
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        this->grid = grid;
        const int n = grid.size();
        Node* root = dfs(0, 0, n - 1, n - 1);
        return root;
    }
};
