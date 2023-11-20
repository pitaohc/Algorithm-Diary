#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    uint32_t getMask(const string& word) {
        uint32_t result = 0;
        for (char ch : word) {
            result |= 1 << (ch - 'a');
        }
        return result;
    }
public:
    int maxProduct(vector<string>& words) {
        int result = 0, n = words.size();
        bool isFound = false;
        sort(words.begin(), words.end(), [](auto& left, auto& right) {
            return left.size() > right.size();
            });
        vector<uint32_t> masks(n, 0);
        for (size_t i = 0; i < n; i++)
        {
            masks[i] = getMask(words[i]);
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                if ((masks[i] & masks[j]) == 0) {
                    result = std::max(result, (int)(words[i].size() * words[j].size()));
                    break;
                }
            }
        }
        return result;
    }
};
