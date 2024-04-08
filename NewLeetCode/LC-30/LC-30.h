#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordSize = words[0].size();
        int sSize = s.size();
        int wSize = words.size();
        int subSize = wSize * wordSize;
        if (sSize < subSize) {
            return {};
        }
        vector<int> res;
        for (int offset = 0; offset < wordSize && offset + subSize <= sSize; ++offset) {
            unordered_map<string, int> um;
            for (int i = 0; i < wSize; ++i) {
                string sub = s.substr(offset + i * wordSize, wordSize);
                ++um[sub];
            }
            for (const auto& word : words) {
                --um[word];
                if (um[word] == 0) {
                    um.erase(word);
                }
            }
            if (um.empty()) {
                res.emplace_back(offset);
            }
#ifdef _DEBUG
            fmt::print("{}: hash: {}\n", offset, um);
            fmt::print("{}: res: {}\n", offset, res);
#endif // _DEBUG

            //开始滑动
            for (int start = offset + wordSize; start < sSize - subSize + 1; start += wordSize)
            {
                string word = s.substr(start + (wSize - 1) * wordSize, wordSize);
                if (++um[word] == 0) {
                    um.erase(word);
                }
                word = s.substr(start - wordSize, wordSize);
                if (--um[word] == 0) {
                    um.erase(word);
                }
                if (um.empty()) {
                    res.emplace_back(start);
                }
#ifdef _DEBUG
                fmt::print("{}: hash: {}\n", start, um);
                fmt::print("{}: res: {}\n", start, res);
#endif // _DEBUG

            }
        }
        return res;
    }
};
