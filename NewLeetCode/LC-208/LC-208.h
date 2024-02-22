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
            //����ÿһ����ĸ
            int index = getIndex(ch);
            if (!node->children[index]) { //��������ڶ�Ӧ�ڵ�
                node->children[index] = new TrieNode(); //������Ӧ��ĸ���ӽڵ�
            }
            else {
                node->isEnd = false; //���ԭ�����нڵ㣬�����isEnd
            }
            node = node->children[index]; //���µ���
        }
        node->isEnd = true; //���һ����ĸ�����ý������
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
