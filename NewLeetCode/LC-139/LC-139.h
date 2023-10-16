#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
constexpr int CHARSETSIZE = 26;
class Trie
{
    Trie* children[CHARSETSIZE];
    bool isEnd;
public:
    Trie()
    {
        isEnd = false;
        memset(children, 0, sizeof(children));
    }
    ~Trie()
    {
        for (size_t i = 0; i < CHARSETSIZE; i++)
        {
            if (children[i] != nullptr)
            {
                delete children[i];
                children[i] = nullptr;
            }
        }
    }
    void insetrWord(const string& s)
    {
        Trie* node = this;
        for (const char ch : s)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    bool find(const string& s)
    {
        Trie* node = this;
        for (const char ch : s)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& word : wordDict)
        {
            trie.insetrWord(word);
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (size_t i = 1; i <= n; i++) //i指向字符串尾部
        {
            for (size_t j = 0; j< i; j++)
            {
                string sub = s.substr(j, i-j);
                if (dp[j] && trie.find(sub))
                {
                    //当前字符串之前的部分能够被完全分割，并且当前字符串能够在字典中被找到
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};