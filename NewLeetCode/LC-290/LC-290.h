#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
private:
    string getNextWord(const string& s,int& pos) {
        const int n = s.size();
        if (pos > n) {
            return "";
        }
        int i = pos;
        while (i < n && s[i] != ' ') {
            ++i;
        }
        string result = s.substr(pos, i - pos);
        pos = i + 1;
        return result;
    }
public:
    bool wordPattern(string pattern, string s) {
        int id = 0;
        int pos = 0;
        const int n = s.size();
        const int m = pattern.size();
        //检查长度是否匹配
        int cnt = 0;
        for (char ch : s) {
            cnt += ch == ' ';
        }
        if (cnt + 1 != m) {
#ifdef _DEBUG
            fmt::print("length not equal\n");
#endif // _DEBUG

            return false;
        }

        unordered_map<char, string> words;
        unordered_map<string, char> ps;
        while (pos < n) {
            string word = getNextWord(s, pos);
            char p = pattern[id];
#ifdef _DEBUG
            fmt::print("p: {}, word: {}, words: {}\n", p, word, words);
#endif // _DEBUG

            if (words.find(p) == words.end() && ps.find(word) == ps.end()) {
                //第一次出现，插入单词
                words[p] = word;
                ps[word] = p;
            }
            else {
                if (words[p] != word || ps[word]!=p) {
                    return false;
                }
            }
            ++id;
        }
        return true;
    }
};

