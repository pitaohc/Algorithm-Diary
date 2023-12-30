#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Trie {
private:
    struct TrieNode {
        bool isEnd;
        static const uint32_t MaxChildren = 26;
        vector<TrieNode*> children;
        TrieNode() {
            isEnd = false;
            children = vector<TrieNode*>(TrieNode::MaxChildren, nullptr);
        }
        ~TrieNode() {
            for (TrieNode* node : children) {
                if (node != nullptr) {
                    delete node;
                }
            }
        }
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    int getIndex(char ch) {
        return ch - 'a';
    }
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            //遍历每一个字母
            int index = getIndex(ch);
            if (!node->children[index]) { //如果不存在对应节点
                node->children[index] = new TrieNode(); //创建对应字母的子节点
            }
            else {
                node->isEnd = false; //如果原本就有节点，则更新isEnd
            }
            node = node->children[index]; //向下迭代
        }
        node->isEnd = true; //最后一个字母，设置结束标记
    }

    bool search(string word) {
        if (word.empty()) {
            return true;
        }
        TrieNode* node = root;
        bool result = true;
        for (char ch : word) {
            int index = getIndex(ch);
            if (node->children[index] != nullptr) {
                node = node->children[index];
            }
            else {
                result = false;
                break;
            }
        }
        result = result && node->isEnd;
        return result;
    }

    bool startsWith(string prefix) {
        if (prefix.empty()) {
            return true;
        }
        TrieNode* node = root;
        bool result = true;
        for (char ch : prefix) {
            int index = getIndex(ch);
            if (node->children[index] != nullptr) {
                node = node->children[index];
            }
            else {
                result = false;
                break;
            }
        }
        return result;
    }
    ~Trie() {
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
