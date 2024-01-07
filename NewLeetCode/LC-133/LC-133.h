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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> nodes;
        if (node == nullptr) {
            return nullptr;
        }

        //bfs获得所有顶点，同时构建新顶点
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (nodes.find(cur) == nodes.end()) {
                nodes.insert({ cur, new Node(cur->val) });
                for (auto neighbor : cur->neighbors) {
                    q.push(neighbor);
                }
            }
        }

        //遍历所有顶点，构建邻接关系
        Node* newNode = nodes[node]; //得到入口顶点
        for (auto& [old, newNode] : nodes) {
            for (auto& neighbor : old->neighbors) {
                newNode->neighbors.emplace_back(nodes[neighbor]);
            }
        }

        return newNode;
    }
};
